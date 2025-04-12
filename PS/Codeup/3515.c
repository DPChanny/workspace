#include<stdio.h>
#include<stdlib.h>

int n;
int** ns;
int* visit;

int dfs(int _y, int _num) {
	if (_y == n) {
		return _num;
	}

	int max = 0;

	for (int _x = 0; _x < n; _x++)
	{
		if (visit[_x]) {
			continue;
		}
		visit[_x] = 1;
		int val = dfs(_y + 1, _num + ns[_y][_x]);
		if (val > max) {
			max = val;
		}
		visit[_x] = 0;
	}

	return max;
}

int main(void) {
	scanf("%d", &n);
	ns = (int**)malloc(sizeof(int*) * n);
	for (int _y = 0; _y < n; _y++)
	{
		ns[_y] = (int*)malloc(sizeof(int) * n);
		for (int _x = 0; _x < n; _x++)
		{
			scanf("%d", &ns[_y][_x]);
		}
	}
	visit = (int*)calloc(n, sizeof(int));

	printf("%d", dfs(0, 0));

	for (int _y = 0; _y < n; _y++)
	{
		free(ns[_y]);
	}
	free(ns);
	free(visit);
}