
#ifndef _CMD_H_
#define _CMD_H_

#include <string.h>
#include <stdbool.h>

void show_manual();
bool cmd_q(char *str);
bool cmd_help(char *str);
bool cmd_add(char *str);
bool cmd_scan(char *str);

void exec_scan(void);
void exec_add(void);

#endif
