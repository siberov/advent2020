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

	const int const dx[] = { 1, 3, 5, 7, 1 };
	const int const dy[] = { 1, 1, 1, 1, 2 };
	int x[] = { 1, 3, 5, 7, 1 };
	int y[] = { 1, 1, 1, 1, 2 };
	int trees[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		while (y[i] < rws) {
			if (map[y[i]][x[i]%cls] == '#')
				trees[i]++;
			x[i] += dx[i];
			y[i] += dy[i];
		}
	}
	printf("Answer: %d*%d*%d*%d*%d = %u trees\n", trees[0], trees[1], trees[2], trees[3], trees[4], trees[0]*trees[1]*trees[2]*trees[3]*trees[4]);
	return 0;
}
