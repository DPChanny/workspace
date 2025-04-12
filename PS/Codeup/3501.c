#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2

#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int n;
	scanf("%d", &n);

	int** ns = (int**)malloc(sizeof(int*) * n);
	for (int _n = 0; _n < n; _n++)
	{
		ns[_n] = (int*)malloc(sizeof(int) * 3);
		scanf("%d%d%d", &ns[_n][0], &ns[_n][1], &ns[_n][2]);
	}

	int* cns = (int*)malloc(sizeof(int) * 6);
	int* bcns = (int*)malloc(sizeof(int) * 3);
	bcns[RED] = ns[0][RED];
	bcns[GREEN] = ns[0][GREEN];
	bcns[BLUE] = ns[0][BLUE];
	for (int _n = 1; _n < n; _n++)
	{
		cns[RED * 2] = bcns[BLUE] + ns[_n][RED];
		cns[RED * 2 + 1] = bcns[GREEN] + ns[_n][RED];
		cns[GREEN * 2] = bcns[RED] + ns[_n][GREEN];
		cns[GREEN * 2 + 1] = bcns[BLUE] + ns[_n][GREEN];
		cns[BLUE * 2] = bcns[GREEN] + ns[_n][BLUE];
		cns[BLUE * 2 + 1] = bcns[RED] + ns[_n][BLUE];

		bcns[RED] = min(cns[RED * 2], cns[RED * 2 + 1]);
		bcns[GREEN] = min(cns[GREEN * 2], cns[GREEN * 2 + 1]);
		bcns[BLUE] = min(cns[BLUE * 2], cns[BLUE * 2 + 1]);
	}

	printf("%d", min(min(bcns[RED], bcns[GREEN]), bcns[BLUE]));

	for (int _n = 0; _n < n; _n++)
	{
		free(ns[_n]);
	}
	free(ns);
	free(cns);
	free(bcns);
}
