#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2

#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int n = 0;

	scanf("%d", &n);

	int** rgb = (int**)malloc(sizeof(int*) * n);
	int** rgb_cal = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		rgb[i] = (int*)malloc(sizeof(int) * 3);
	}

	for (int i = 0; i < n; i++)
	{
		scanf(" %d %d %d", &rgb[i][RED], &rgb[i][GREEN], &rgb[i][BLUE]);
	}

	for (int i = 0; i < n; i++)
	{
		rgb_cal[i] = (int*)malloc(sizeof(int) * 3);
	}
	for (int j = 0; j < 3; j++)
	{
		rgb_cal[0][j] = rgb[0][j];
	}

	for (int i = 1; i < n; i++)
	{
		rgb_cal[i][RED] = min(rgb_cal[i - 1][GREEN], rgb_cal[i - 1][BLUE]) + rgb[i][RED];
		rgb_cal[i][GREEN] = min(rgb_cal[i - 1][RED], rgb_cal[i - 1][BLUE]) + rgb[i][GREEN];
		rgb_cal[i][BLUE] = min(rgb_cal[i - 1][RED], rgb_cal[i - 1][GREEN]) + rgb[i][BLUE];
	}

	printf("%d", min(min(rgb_cal[n - 1][RED], rgb_cal[n - 1][GREEN]), rgb_cal[n - 1][BLUE]));

	for (int i = 0; i < n; i++)
	{
		free(rgb[i]);
		free(rgb_cal[i]);
	}
	free(rgb);
	free(rgb_cal);

	return 0;
}