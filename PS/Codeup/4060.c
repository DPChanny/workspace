#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int h, w;
int** visited;
int** map;

void dfs(int _x, int _y, int _status) {
	if (_x < 0 || _x > w - 1 || _y < 0 || _y > h - 1) {
		return;
	}

	if (map[_y][_x] == _status && !visited[_y][_x]) {
		visited[_y][_x] = 1;

		dfs(_x + 1, _y, _status);
		dfs(_x - 1, _y, _status);
		dfs(_x, _y + 1, _status);
		dfs(_x, _y - 1, _status);
	}
}

int main(void) {
	scanf("%d %d", &h, &w);

	map = (int**)malloc(sizeof(int*) * h);
	visited = (int**)malloc(sizeof(int*) * h);
	for (int _h = 0; _h < h; _h++)
	{
		map[_h] = (int*)malloc(sizeof(int) * w);
		visited[_h] = (int*)calloc(w, sizeof(int));
		for (int _w = 0; _w < w; _w++)
		{
			scanf("%d", &map[_h][_w]);
		}
	}

	int off = 0;
	int on = 0;
	for (int _h = 0; _h < h; _h++)
	{
		for (int _w = 0; _w < w; _w++)
		{
			if (!visited[_h][_w]) {
				dfs(_w, _h, map[_h][_w]);
				if (map[_h][_w]) {
					on++;
				}
				else {
					off++;
				}
			}
		}
	}

	printf("%d %d", off, on);

	for (int _h = 0; _h < h; _h++)
	{
		free(map[_h]);
		free(visited[_h]);
	}
	free(map);
	free(visited);
}