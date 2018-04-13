#Makefile

test:
	gcc -lreadline main.c src/exec.c src/cmd.c src/manual.c src/scan.c src/scan_exec.c -o test

.PHONY: clean

clean:
	rm test
