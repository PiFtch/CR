// scan mode 
#include "../include/scan.h"
/*
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void show_scan_manual();

bool scan_cmd_q(char *str);
bool scan_cmd_help(char *str);
bool scan_cmd_search_id(char *str);
bool scan_cmd_avg(char *str);
bool scan_cmd_o(char *str);


struct stuinfo {
	char id[8];
	char name[16];
	float score0,score1,score2,score3;
//	float score[4];
	float avg;
	struct stuinfo *next;
};
bool scan_cmd(char *str, struct stuinfo *p);
void scan_search_id(struct stuinfo *p);
void scan_avg(struct stuinfo *p);
void scan_o(struct stuinfo *p);

*/

void scan_mode(struct stuinfo *phead) {
	printf("enter scan mode\n");
	show_scan_manual();

	// accept user's inputs
	static char *scan_line_read = NULL;	// user's command
	while (1) {
		if (scan_line_read) {
			free(scan_line_read);
			scan_line_read = NULL;
		}

		struct stuinfo *p = phead;
		scan_line_read = readline("(scan mode) ");
		if (scan_cmd(scan_line_read, p))
			break;
	}
}


void show_scan_manual() {
	FILE *fp;
	fp = fopen("data/.scan_manual", "r");
	char ch;
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
}

bool scan_cmd(char *str, struct stuinfo *p) {	// p point to the linked list's head
	if (scan_cmd_q(str))
		return true;
	else if (scan_cmd_help(str)) {
		show_scan_manual();
		return false;
	} else if (scan_cmd_search_id(str)) {
		scan_search_id(p);	
		return false;
	} else if (scan_cmd_avg(str)) {
	    scan_avg(p);
		return false;
	} else if (scan_cmd_o(str)) {
		scan_o(p);
		return false;
	} else {
		printf("invalid command, enter 'help' for help.\n");
		return false;
	}	
}



bool scan_cmd_q(char *str) {
	const char *scan_quit = "q";
	if (strcmp(scan_quit, str) == 0)
		return true;
	return false;
}

bool scan_cmd_help(char *str) {
	const char *scan_help = "help";
	if (!strcmp(scan_help, str))
		return true;
	return false;
}

bool scan_cmd_search_id(char *str) {
	const char *scan_search_id = "searchid";
	if (!strcmp(scan_search_id, str))
		return true;
	return false;
}

bool scan_cmd_avg(char *str) {
	const char *scan_avg = "avg";
	if (!strcmp(scan_avg, str))
		return true;
	return false;
}

bool scan_cmd_o(char *str) {
	const char *scan_o = "o";
	if (!strcmp(scan_o, str))
		return true;
	return false;
}

float sum_score[4] = {0,0,0,0};
void scan_avg(struct stuinfo *p) {
	float sum = 0.0;
	while (p != NULL) {
		printf("%s %s\n", p->id, p->name);
		sum = p->score0 + p->score1 + p->score2 + p->score3;
/*		for (int i = 0; i < 4; i++ )
			sum += (p->score)[i];
*/
		p->avg = sum / 4;
		
		p = p->next;
		sum = 0.0;
	}
	printf("Done. Every student's average score has been calculated.\n");
}

void scan_o(struct stuinfo *p) {
	FILE *fp;
	fp = fopen("data/output", "w");

	while (p != NULL) {
		fprintf(fp, "%s %s %4.1f %4.1f %4.1f %4.1f %4.1f\n", p->id, p->name, p->score0, p->score1, p->score2, p->score3, p->avg);
//		for (int i = 0; i < 4; i++)
//			fprintf(fp, " 4.1f", (p->score)[i]);
//		fprintf(fp, " %4.1f", p->avg);	
		p = p->next;
	}

	fclose(fp);
}


/*
void scan_search_id(struct stuinfo *p) {
	char *target;
	printf("enter student's id: ");
//	scanf("%s", target);
	target = readline("");
	printf("searching for id \"%s\"...\n", target);

	while (p != NULL) {
		if (!strcmp(target, p->id)) {	// id found
			printf("found student %s %s\n", p->id, p->name);
			break;
		}
		p = p->next;
	}
	printf("enter m to modify: ");
	char ch[5];
	scanf("%s", &ch);
	if (!strcmp(ch, "mod"))
		printf("now modify: ");
//	while (p != NULL && p->id == 
}
*/
