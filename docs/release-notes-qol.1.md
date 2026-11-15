# AmneziaVPN Linux QoL — v5.1.0.6+qol.1

## Highlights

- **Themes** — 11 palettes, 12 accent colours and a light mode. Switching is
  instant and survives a restart.
- **Native CLI** — `status`, `servers`, `connect`, `disconnect`, `watch`, plus
  `--json` and `--redact`.
- **Split tunneling** — the kernel route table was read through a fixed 8 KiB
  buffer; once it passed about a hundred entries the gateway lookup returned
  empty and every exclusion route was skipped. Fixed.
- **Window** — opens at 360x670 instead of the 600x800 maximum.

## Install

```bash
chmod +x AmneziaVPN_5.1.0.6_linux_x64+qol.1.run
sudo ./AmneziaVPN_5.1.0.6_linux_x64+qol.1.run \
  --accept-licenses --accept-messages --confirm-command install
```

The installer replaces `/opt/AmneziaVPN` and keeps `~/.config/AmneziaVPN.ORG/`.

## Notes

- English only: the new strings are not translated yet.
- Light variants ship for Catppuccin, Dracula and Rosé Pine; the rest are dark
  only.
- Tested on Arch Linux (Hyprland, x86_64).
