#include<stdio.h>
#include<stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2

#define min(a,b) (((a) < (b)) ? (a) : (b))

int R(int _n, int** _rgb, int** _rgb_cal);
int G(int _n, int** _rgb, int** _rgb_cal);
int B(int _n, int** _rgb, int** _rgb_cal);

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
		rgb_cal[i] = (int*)malloc(sizeof(int) * 3);
		for (int j = 0; j < 3; j++)
		{
			rgb_cal[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf(" %d %d %d", &rgb[i][RED], &rgb[i][GREEN], &rgb[i][BLUE]);
	}
	
	printf("%d", min(min(R(n - 1, rgb, rgb_cal),G(n - 1, rgb, rgb_cal)),B(n- 1, rgb, rgb_cal)));

	for (int i = 0; i < n; i++)
	{
		free(rgb[i]);
		free(rgb_cal[i]);
	}
	free(rgb);
	free(rgb_cal);

	return 0;
}

int R(int _n, int** _rgb, int** _rgb_cal) {
	if (!_rgb_cal[_n][RED]) {
		if (_n == 0) {
			_rgb_cal[_n][RED] = _rgb[_n][RED];
		}
		else {
			_rgb_cal[_n][RED] = min(G(_n - 1, _rgb, _rgb_cal), B(_n - 1, _rgb, _rgb_cal)) + _rgb[_n][RED];
		}
	}

	return _rgb_cal[_n][RED];
}

int G(int _n, int** _rgb, int** _rgb_cal) {
	if (!_rgb_cal[_n][GREEN]) {
		if (_n == 0) {
			_rgb_cal[_n][GREEN] = _rgb[_n][GREEN];
		}
		else {
			_rgb_cal[_n][GREEN] = min(R(_n - 1, _rgb, _rgb_cal), B(_n - 1, _rgb, _rgb_cal)) + _rgb[_n][GREEN];
		}
	}

	return _rgb_cal[_n][GREEN];
}

int B(int _n, int** _rgb, int** _rgb_cal) {
	if (!_rgb_cal[_n][BLUE]) {
		if (_n == 0) {
			_rgb_cal[_n][BLUE] = _rgb[_n][BLUE];
		}
		else {
			_rgb_cal[_n][BLUE] = min(G(_n - 1, _rgb, _rgb_cal), R(_n - 1, _rgb, _rgb_cal)) + _rgb[_n][BLUE];
		}
	}

	return _rgb_cal[_n][BLUE];
}