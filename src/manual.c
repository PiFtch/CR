#include <stdio.h>
void show_manual() {
	FILE *fp;	
	fp = fopen("data/.manual", "r");
//	FILE *fp2;
//	fp2 = fopen("data/scores", "a");
//	fputs("try.", fp2);
	char ch;
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
}
/*
int main() {
	show_manual();
	return 0;
}
*/
