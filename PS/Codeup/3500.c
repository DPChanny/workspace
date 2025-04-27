#include<stdio.h>
#include<stdlib.h>

int map[9][9];
int map_checked[9][9] = {0, }; 
char map_print[9][9];

int check_map(int _x, int _y) {
	if (_x >= 9 || _y >= 9 || _x < 0 || _y < 0) {
		return 0;
	}
	return map[_y][_x];
}

void dfs(int _x, int _y) {
	if (map_checked[_y][_x] || _x >= 9 || _y >= 9 || _x < 0 || _y < 0) {
		return;
	}
	map_checked[_y][_x] = 1;
	int count =
		check_map(_x, _y + 1) + check_map(_x, _y - 1) +
		check_map(_x + 1, _y - 1) + check_map(_x + 1, _y + 1) + check_map(_x + 1, _y) +
		check_map(_x - 1, _y - 1) + check_map(_x - 1, _y + 1) + check_map(_x - 1, _y);
	if (map[_y][_x]) {
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				if (y == _y && x == _y) {
					printf("-1 ");
				}
				else {
					printf("_ ");
				}
			}
			printf("\n");
		}
		exit(EXIT_SUCCESS);
	}
	else {
		map_print[_y][_x] = count + '0';
	}
	if (!count) {
		dfs(_x - 1, _y);
		dfs(_x + 1, _y);
		dfs(_x, _y + 1);
		dfs(_x - 1, _y + 1);
		dfs(_x + 1, _y + 1);
		dfs(_x, _y - 1);
		dfs(_x + 1, _y - 1);
		dfs(_x - 1, _y - 1);
	}
}

int main(void) {
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			scanf("%d", &map[y][x]);
			map_print[y][x] = '_';
		}
	}
	int x, y;
	scanf("%d %d", &y, &x);

	dfs(x - 1, y - 1);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			printf("%c ", map_print[y][x]);
		}
		printf("\n");
	}
}