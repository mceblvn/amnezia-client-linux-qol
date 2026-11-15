# AmneziaVPN Linux QoL

Fork of [amnezia-vpn/amnezia-client](https://github.com/amnezia-vpn/amnezia-client)
with Linux quality-of-life changes: **themes with an accent picker and a light
scheme**, a **native CLI inside the same GUI binary**, and a fix for site split
tunneling that silently stopped installing routes.

> Upstream readme and docs: [amnezia-vpn/amnezia-client](https://github.com/amnezia-vpn/amnezia-client#readme),
> [docs.amnezia.org](https://docs.amnezia.org).

<p align="center">
  <img src="docs/appearance.png" alt="Settings — Appearance" width="760">
</p>

**Linux only.** Built, packaged and tested on Linux. The CLI is not built or
packaged for macOS and Windows here, and `deploy/build_cli_package.sh` is
Linux-only.

## What is in here

### Themes

Eleven palettes, twelve accent colours and a real light scheme. Switching is
instant, survives a restart and recolours the whole interface: the design has
**56 colour tokens**, all derived from **14 base colours** of a theme, so a
preset is data rather than a second stylesheet. Every palette is checked
against **WCAG AA** (4.5:1) by a test, including text on accent buttons.

**Amnezia (default)** keeps the original look and adds two knobs:

- **Dark / Light** scheme
- **12 accents** — amber, orange, red, pink, purple, violet, indigo, blue, sky,
  teal, green, lime

**Presets** are the whole look at once, no knobs:

| Theme | Variants | Background | Accent |
| --- | --- | --- | --- |
| Catppuccin | Latte (light) · Mocha (dark) | `#EFF1F5` · `#1E1E2E` | `#8839EF` · `#CBA6F7` |
| Dracula | Dracula (dark) · Alucard (light) | `#282A36` · `#FFFBEB` | `#BD93F9` · `#644AC9` |
| Everforest | dark | `#272E33` | `#A7C080` |
| Graphite Violet | dark | `#0D0D10` | `#8B5CF6` |
| Kanagawa | dark | `#1F1F28` | `#7E9CD8` |
| Nord | dark | `#2E3440` | `#88C0D0` |
| Rosé Pine | Moon (dark) · Dawn (light) | `#232136` · `#FAF4ED` | `#C4A7E7` · `#907AA9` |
| Tokyo Night | dark | `#1A1B26` | `#7AA2F7` |

Families with a light variant sit side by side in the list; the rest take a full
row. Adding a theme is one entry of fourteen colours in
`client/core/theme/themePalettes.cpp`.

### Native CLI

`status`, `servers`, `connect`, `disconnect`, `watch` — plus `--json` and
`--redact`. Built for scripted control: status bars, widgets, hotkeys,
automation.

```bash
AmneziaVPN status [--json] [--redact]      # what is connected right now
AmneziaVPN servers [--json]                # configured servers, GUI order
AmneziaVPN connect [index] [--json]        # default server, or the Nth
AmneziaVPN disconnect [--json]             # idempotent
AmneziaVPN watch [--json] [--redact]       # one JSON line per state change
```

`status`:

```
connected: yes
  device:  10.13.13.2
  gateway: 203.0.113.7
  rx/tx:   12450816 / 1048576 bytes
  since:   Mon Nov 10 09:14:22 2026
```

The CLI process sends one line-delimited JSON request to the running GUI over
`QLocalSocket` (`AmneziaVPNInstance`) and exits: 0 ok, 1 failure, 2 usage.
`connect` and `disconnect` confirm *acceptance*, not the result — connect is
asynchronous, so poll `status` or keep `watch` open. `--redact` masks IPs
(`1.2.3.4` → `1.2.*.*`). With no GUI running, `status` falls back to the
privileged daemon, so a tunnel that outlived the window still shows up —
without server name and protocol, which the daemon does not know.

### Split tunneling fix

Upstream reads the kernel route table through a fixed 8 KiB netlink buffer
(`NetworkUtilities::getGatewayAndIface`). Once the table passes roughly a
hundred entries — which the exclusion routes of a large site list create by
themselves — the dump does not fit. The lookup then returns an empty gateway
and every exclusion route is skipped with `No default gateway available`;
routes already installed are never removed either, because the delete path
uses the same lookup.

The fix grows the buffer, treats a full buffer as the end of the dump, caches
the gateway for the session, skips empty endpoints, and deletes per-prefix
routes instead of inserting them.

## Branches

| branch | purpose |
| --- | --- |
| `main` | mirrors `upstream/dev`; no local commits |
| `qol` | integration branch: `main` plus every feature below |
| `feat/cli` | native CLI |
| `feat/theme` | themes, accents, light scheme |
| `fix/linux-exclusion-routes` | split tunneling fix |

`qol` is `main` plus the feature branches. Features stay independent so each
can be rebased onto a new upstream on its own and, where it is a bug fix,
offered upstream as a pull request.

## Building

Requirements: Qt 6.10.1 from aqtinstall with `qtremoteobjects qt5compat
qtshadertools qthttpserver qtwebsockets`, Qt Installer Framework, Conan 2.34,
CMake 3.25+, Ninja, GCC.

```bash
git clone --recursive https://github.com/mceblvn/amnezia-client-linux-qol.git
cd amnezia-client-linux-qol
cp deploy/.cli-env.example deploy/.cli-env     # fill in the gateway keys
deploy/build_cli_package.sh --generator Ninja
```

→ `deploy/build/AmneziaVPN_5.1.0.6_linux_x64.run`. Add `--suffix +qol.1` to
tag the package name.

The script is a thin wrapper over `deploy/build.sh --installer all`: it
sources `deploy/.cli-env`, refuses to build with empty keys, and verifies the
keys ended up in the binary. `deploy/build.sh` finds Qt and QtIFW in the
aqtinstall layout (`~/Qt`, or `QT_INSTALL_DIR`/`QT_ROOT_PATH`/`QIF_ROOT_PATH`).

Use the aqt Qt, not the distro one: Qt's deploy on a distro Qt copies an
incomplete plugin set, drags `libc` and `libstdc++` into the bundle, and dies
on RPATH.

## Syncing with upstream

```bash
git fetch upstream
git rebase upstream/dev feat/cli
git rebase upstream/dev feat/theme
git rebase upstream/dev fix/linux-exclusion-routes
git checkout -B qol feat/cli
git cherry-pick main..fix/linux-exclusion-routes
git cherry-pick main..feat/theme
```

## Premium keys

`deploy/.cli-env` (gitignored) holds the gateway keys and mirror endpoints.
Without them everything works except Premium API calls. Key format is strict:
one line, literal `\n`, no trailing newline — the PEM bytes are hashed into
the AES key for proxy payloads, one extra byte breaks the whole path.

## Install layout

```
/opt/AmneziaVPN/bin/AmneziaVPN            # client + CLI
/opt/AmneziaVPN/bin/AmneziaVPN-service    # privileged service
/opt/AmneziaVPN/{lib,plugins,qml}         # bundled Qt
~/.config/AmneziaVPN.ORG/AmneziaVPN.conf  # config, kept across installs
```

## License

GNU General Public License v3.0 (see LICENSE). This fork is not affiliated
with or endorsed by the Amnezia project.
