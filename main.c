#include "include/main.h"
/*
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
void show_manual();
//bool cmd_q(char* str);
bool cmd(char* str);
*/
void main() {
	printf("This is a student curriculum and performance management system.\n");
	show_manual();	


	// accept user's inputs
	static char *line_read = NULL; // user's command
	while (1) {
		if (line_read) {
			free(line_read);
			line_read = NULL;
		}
		
		line_read = readline("(ManagementSystem) ");
		printf("%s\n", line_read);
//		if (cmd_q(line_read))
//			break;
		if (cmd(line_read))
			break;
	}		
}
/*
bool cmd_q(char* str) {
	int i = 0;
	while ((str[i]) != '\0') {
		if (str[i] != 'q')
			return false;
		i++;
	}
	return true;
	
}
*/
