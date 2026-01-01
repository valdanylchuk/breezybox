#pragma once

/**
 * @brief Initialize the exec subsystem (call once at startup)
 */
void breezybox_exec_init(void);

/**
 * @brief Execute a command with redirect support
 * 
 * Supports:
 *   cmd > file      Output redirect (overwrite)
 *   cmd >> file     Output redirect (append)
 *   cmd < file      Input redirect
 *   cmd1 | cmd2     Pipe (serialized via temp file)
 * 
 * @param cmdline Command line to execute
 * @return Command return code, or -1 on redirect error
 */
int breezybox_exec(const char *cmdline);