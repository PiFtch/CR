#include "../include/exec.h"
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stuinfo {
	char id[8];
	char name[16];
	float score0, score1, score2, score3;
//	float score[4];
	float avg;	
	struct stuinfo *next;
};

void scan_mode(struct stuinfo *p);
*/
void exec_add() {
	struct {
		char *num;
		char *name;
		float *score;
	}stu;
	printf("input student number, name, scores(divided by space):\n");
//	scanf("%s %s %f", stu.num, stu.num, stu.score);	
	stu.name = "piftch";
	FILE *fp;
	fp = fopen("data/scores", "a");
	fputs(stu.name, fp);
	fputs("\n", fp);
	fclose(fp);
}

void exec_scan() {
	FILE *fp;
	fp = fopen("data/file", "r");
/*	struct stuinfo {
		char id[8];
		char name[16];
		int score0, score1, score2, score3;
		
		struct stuinfo *next;
	};  */
	struct stuinfo *head = NULL;
	struct stuinfo *prev, *current;

	while (!feof(fp)) {
		current = (struct stuinfo *)malloc(sizeof(struct stuinfo));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;

		fscanf(fp, "%s %s %f %f %f %f", current->id, current->name, &(current->score0),&(current->score1),&(current->score2),&(current->score3));
//		fscanf(fp, "%s %s", current->id, current->name);
		
//		for (int i = 0; i < 4; i++)
//			fscanf(fp, "%f", (current->score)[i]);

		if ((current->id)[0] != '\0')
			prev = current;
		else {	
			prev->next = NULL;
			free(current);
		}
	}
//	printf("%s %f %f\n", prev->id, prev->score2, prev->avg);

	struct stuinfo *p = head;
	while (p != NULL) {
		printf("%6s %3s %4.1f %4.1f %4.1f %4.1f\n", p->id, p->name, p->score0, p->score1, p->score2, p->score3);
//		printf("%6s %3s", p->id, p->name);
/*		for (int i = 0; i < 4; i++)
			printf(" %4.1f", (p->score)+i);
		printf("\n");         */

		p = p->next;
	}

	p = head;
	scan_mode(p);	

}

