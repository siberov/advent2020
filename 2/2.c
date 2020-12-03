#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;
	char line[100];
	int valid_passwords = 0;
	fp = fopen("in.txt", "r");
	while (fgets(line, 100, fp)) {
		int lower, upper;
		int occ = 0;
		char l[10] = {0};
		char u[10] = {0};
		int i;
		char sought;
		for (i = 0; i < 10 && line[i] != '-'; i++)
			l[i] = line[i];
		l[i++] = '\0';
		lower = atoi(l);
		for (int j = 0; j < 10 && line[i] != ' '; i++, j++)
			u[j] = line[i];
		u[i] = '\0';
		upper = atoi(u);
		sought = line[++i];
		i += 2; // Point to position before first letter
		// No bounds checking, we trust the input :^)
		if ((line[i + lower] == sought && line[i + upper] != sought) ||
		    (line[i + lower] != sought && line[i + upper] == sought))
			valid_passwords++;
	}
	fclose(fp);
	printf("Valid passwords: %d\n", valid_passwords);
	return 0;
}
