#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define SIZE 7

int map[SIZE][SIZE];
int visited[SIZE][SIZE];

int dfs(int _x, int _y, int _color) {
	if (_x < 0 || _x > SIZE - 1 || _y < 0 || _y > SIZE - 1) {
		return 0;
	}

	if (map[_y][_x] == _color && !visited[_y][_x]) {
		visited[_y][_x] = 1;

		return 
			1 + 
			dfs(_x, _y - 1, _color) + 
			dfs(_x + 1, _y, _color) + 
			dfs(_x - 1, _y, _color) + 
			dfs(_x, _y + 1, _color);
	}
	else {
		return 0;
	}
}

int main(void) {
	for (int _h = 0; _h < SIZE; _h++)
	{
		for (int _w = 0; _w < SIZE; _w++)
		{
			scanf("%d", &map[_h][_w]);
		}
	}
	memset(visited, 0, sizeof(int) * SIZE * SIZE);

	int count = 0;
	for (int _h = 0; _h < SIZE; _h++)
	{
		for (int _w = 0; _w < SIZE; _w++)
		{
			if (!visited[_h][_w]) {
				if (dfs(_w, _h, map[_h][_w]) >= 3) {
					count++;
				}
			}
		}
	}

	printf("%d", count);
}