# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.2] - 2026-05-30

### Added
- NOTIFY_RX handler for keyboards where INPUT_EVENT is incompatible with esp_hidh

## [1.0.1] - 2026-02-15

### Fixed
- Readme typos

## [1.0.0] - 2026-02-15

### Added
- Initial release
- Character push mode via bt_keyboard_set_char_callback()
- Game-friendly polling mode via bt_keyboard_is_pressed()
- Known issue: requires reboot after pairing
- Good performance proven in BreezyBox
