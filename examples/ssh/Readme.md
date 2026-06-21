# Headless SSH BreezyBox demo for esp32-s3

A simple headless BreezyBox demo that skips BT keyboard and physical display to save more SRAM for testing SSH.

## Usage:

- Possibly update sdkconfig.defaults and partitions.csv for your device
- Build and flash with idf.py as usually
- Connect the ESP-IDF Monitor console via USB
- Use `wifi` and `sshd` commands for setup
- Use some ssh client to connect (tested with Tabby)