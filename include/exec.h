#ifndef _EXEC_H_
#define _EXEC_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stuinfo {
	char id[8];
	char name[16];
	float score0, score1, score2, score3;
	// float score[4];
	float avg;
	struct stuinfo *next;
};

void scan_mode(struct stuinfo *p);


#endif
