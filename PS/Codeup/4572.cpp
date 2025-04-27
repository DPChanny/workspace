#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#include<vector>

int h, w;
int** map;
std::vector<int> area;
int count;

void dfs(int _x, int _y) {
	if (_x < 0 || _x > w - 1 || _y < 0 || _y > h - 1) {
		return;
	}

	if (!map[_y][_x]) {
		map[_y][_x] = 1;

		area[count]++;

		dfs(_x + 1, _y);
		dfs(_x - 1, _y);
		dfs(_x, _y + 1);
		dfs(_x, _y - 1);
	}
}

int main(void) {
	int k;
	scanf("%d %d %d", &h, &w, &k);

	map = (int**)malloc(sizeof(int*) * h);
	for (int _h = 0; _h < h; _h++)
	{
		map[_h] = (int*)calloc(w, sizeof(int));
	}

	for (int _k = 0; _k < k; _k++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				map[y][x] = 1;
			}
		}
	}

	count = 0;
	for (int _h = 0; _h < h; _h++)
	{
		for (int _w = 0; _w < w; _w++)
		{
			if (!map[_h][_w]) {
				area.push_back(0);
				dfs(_w, _h);
				count++;
			}
		}
	}

	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		int id = 0;
		for (int j = 1; j < area.size(); j++)
		{
			if (area[j] < area[id]) {
				id = j;
			}
		}
		printf("%d ", area[id]);
		area.erase(area.begin() + id);
	}

	for (int _h = 0; _h < h; _h++)
	{
		free(map[_h]);
	}
	free(map);
}