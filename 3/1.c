#include <stdio.h>
#include <stdlib.h>

int rows(FILE *f) {
	char buf[100];
	int ret = 0;
	while (fgets(buf, sizeof(buf), f)) ret++;
	rewind(f);
	return ret;
}

int cols(FILE *f) {
	int ret = 0;
	char c;
	while (((c = fgetc(f)) != '\n') && (c != '\0'))
		ret++;
	rewind(f);
	return ret - 1;
}

int main(void) {
	FILE *fp = fopen("in.txt", "r");
	int cls = cols(fp);
	int rws = rows(fp);
	char map[rws][cls];
	for (int i = 0; i < rws; i++) {
		for (int j = 0; j < cls; j++) {
			char c;
			while (((c = fgetc(fp)) != '.') && (c != '#'));
			map[i][j] = c;
		}
	}
	fclose(fp);

	int x = 3;
	int y = 1;
	int trees = 0;
	while (y < rws) {
		if (map[y][x%cls] == '#')
			trees++;
		x += 3;
		y++;
	}
	printf("Answer: %d trees\n", trees);
	return 0;
}
