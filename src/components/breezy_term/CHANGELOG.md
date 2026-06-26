# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.3] - 2026-06-26

### Added
- Kconfig settings: VTERM_COLS, VTERM_ROWS

## [1.0.2] - 2026-06-21

### Added
- Screen size management adapted for ssh compatibility (vterm_set_size_override)

## [1.0.1] - 2026-02-15

### Fixed
- Build error caused by s_active_vt

## [1.0.0] - 2026-02-14

### Added
- Initial release
- Enough Esc and ANSI codes for simplified VI
- Fixed size for now
- Good performance proven in BreezyBox
- 4 VTs by default
- 16 colors (SGR), palette support
- save/restore on switching to graphics mode
