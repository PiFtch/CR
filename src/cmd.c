// cmd.c -- resolute the command user entered and execute relevant operations
#include "../include/cmd.h"
/*
#include <string.h>
#include <stdbool.h>
void show_manual();
bool cmd_q(char *str);
bool cmd_help(char *str);
bool cmd_add(char *str);
bool cmd_scan(char *str);
void exec_scan(void);
void exec_add(void);
*/
bool cmd(char* str) {
	if (cmd_q(str)) {
		return true;
	}
	if (cmd_help(str)) {
//		exec_help();
		show_manual();
		return false;
	}
	if (cmd_add(str)) {
		exec_add();
		return false;
	}
	if (cmd_scan(str)) {
		exec_scan();
		return false;
	}
}	


bool cmd_q(char* str) {
	
	const char *quit = "q";
	if (strcmp(quit, str) == 0)
		return true;
	return false;
}	

bool cmd_help(char *str) {
	const char *help = "help";
	if (!strcmp(help, str))
		return true;
	return false;
}

bool cmd_add(char *str) {
	const char *add = "add";
	if (!strcmp(add, str))
		return true;
	return false;
}

bool cmd_scan(char *str) {
	const char *scan = "scan";
	if (!strcmp(scan, str))
		return true;
	return false;
}
