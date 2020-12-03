#include <stdio.h>


void sort(int *arr, int len) {
	int i;
	for (i = 1; i < len; i++) {
		int j;
		for (j = i; j > 0 && arr[j-1] > arr[j]; j--) {
			int tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
		}
	}
}

int hasElement(int *arr, int len, int elem) {
	int i = len/2;
	int delta = len/4;
	while (arr[i] != elem) {
		i = arr[i] > elem ? i-delta : i+delta;
		delta /= 2;
		if (!delta) return 0;
	}
	return 1;
}

int main(void) {
	int numinp = 0;
	int i;
	FILE *fp = fopen("in.txt", "r");
	while (fscanf(fp, "%d\n", &i)) {
		numinp++;
	}
	fclose(fp);

	int arr[numinp];
	fp = fopen("in.txt", "r");
	i = 0;
	while (fscanf(fp, "%d\n", &arr[i++]));
	sort(arr, numinp);
	fclose(fp);
	// Apparently I suck att IO in C, but now we have a sorted array of the numbers.
	// Now to find the numbers ...
	
	int j;
	for (i = 0; i < numinp; i++) {
		int a = arr[i];
		for (j = 0; j < numinp; j++) {
			int b = arr[j];
			if (a + b >= 2020) continue;
			if (hasElement(arr, numinp, 2020 - (a + b))) {
				printf("Solution: %d * %d * %d = %d\n", a, b, 2020-(a+b), a*b*(2020-(a+b)));
				return 0;
			}
		}
	}
	/*
	for (i = 0; i < numinp; i++) {
		if (hasElement(arr, numinp, 2020 - arr[i])) {
			printf("Solution: %d * %d = %d\n", arr[i], 2020 - arr[i], arr[i] * (2020-arr[i]));
		}
	}
	*/
}
