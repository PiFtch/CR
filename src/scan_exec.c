#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

struct stuinfo {
	char id[8];
	char name[16];
	float score0,score1,score2,score3;
//	float score[4];
	float avg;
	struct stuinfo *next;
};

void scan_search_id(struct stuinfo *ps);

void scan_search_id(struct stuinfo *ps) {
	struct stuinfo *p = ps;
	char *target;
	bool FOUND = false;
	printf("enter student's id: ");
	target = readline("");
	printf("searching for student id: %s......\n", target);

	while (p != NULL) {
		// found
		if (!strcmp(target, p->id)) {
			FOUND = true;
			printf("found: id: %s name: %s %4.1f %4.1f %4.1f %4.1f\n", p->id, p->name, p->score0, p->score1, p->score2, p->score3);
/*			printf("found: id: %s name: %s", p->id, p->name);
			for (int i = 0; i < 4; i++)
				printf(" %4.1f", (p->score)[i]);
			printf("\n");
			*/
			break;
		}
		p = p->next;
	}

	if (FOUND) {
		char ch[5];
		printf("enter mod to modify score0, del to delete this data: ");
		scanf("%s", ch);
		if (!strcmp(ch, "mod")) {
			scanf("%f", &(p->score0));
//			scanf("%f", (p->score)[0]);
			printf("now score0 is %4.1f\n", p->score0);
		} else if (!strcmp(ch, "del")) {

		} else {
			printf("invalid command\n");
		}
	} else {
		printf("id %s not found\n", target);
	}
}
