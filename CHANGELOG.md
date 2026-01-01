# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2025-01-01

### Added
- Initial release
- File commands: ls, cat, head, tail, more, wc, cp, mv, rm, mkdir
- Navigation: cd, pwd
- System commands: free, df, du, date, clear, sh, help
- Networking: wifi scan/connect/disconnect/status/forget, httpd
- ELF loader: eget for downloading programs from GitHub
- ANSI 16-color support
- I/O redirection (>, >>, <) and pipes (|)
- Command history and tab completion via linenoise
- Hotkey switching between virtual terminals (F1-F4)
- Linker wrapping for transparent CWD support