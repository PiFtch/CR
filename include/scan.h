#ifndef _SCAN_H_
#define _SCAN_H_

#include "../include/exec.h"
#include <readline/readline.h>
#include <stdbool.h>

void show_scan_manual();

bool scan_cmd_q(char *str);
bool scan_cmd_help(char *str);
bool scan_cmd_search_id(char *str);
bool scan_cmd_avg(char *str);
bool scan_cmd_o(char *str);

bool scan_cmd(char *str, struct stuinfo *p);
void scan_search_id(struct stuinfo *p);
void scan_avg(struct stuinfo *p);
void scan_o(struct stuinfo *p);

#endif
