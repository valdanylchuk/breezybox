#pragma once

#include "esp_console.h"

// Command handlers - called by esp_console
int cmd_echo(int argc, char **argv);
int cmd_pwd(int argc, char **argv);
int cmd_cd(int argc, char **argv);
int cmd_ls(int argc, char **argv);
int cmd_cat(int argc, char **argv);
int cmd_mkdir(int argc, char **argv);
int cmd_cp(int argc, char **argv);
int cmd_mv(int argc, char **argv);
int cmd_rm(int argc, char **argv);
int cmd_df(int argc, char **argv);
int cmd_du(int argc, char **argv);
int cmd_date(int argc, char **argv);
int cmd_eget(int argc, char **argv);
int cmd_wifi(int argc, char **argv);
int cmd_httpd(int argc, char **argv);
int cmd_head(int argc, char **argv);
int cmd_tail(int argc, char **argv);
int cmd_more(int argc, char **argv);
int cmd_wc(int argc, char **argv);