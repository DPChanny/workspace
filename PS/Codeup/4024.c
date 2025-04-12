#include<stdio.h>
#include<stdlib.h>

#define LAKE 'L'

int** map;
int height, width;

//인자로 오는 호수와 이어져 있는 호수의 값을 0으로 변경
void dfs(int _x, int _y) {
	if (_x < 0 || _x > width - 1 || _y < 0 || _y > height - 1) {
		return;
	}

	if (map[_y][_x]) {
		map[_y][_x] = 0;

		dfs(_x + 1, _y);
		dfs(_x + 1, _y + 1);
		dfs(_x + 1, _y - 1);

		dfs(_x - 1, _y);
		dfs(_x - 1, _y + 1);
		dfs(_x - 1, _y - 1);

		dfs(_x, _y + 1);
		dfs(_x, _y - 1);
	}
}

int main(void) {
	scanf("%d %d", &width, &height);

	map = (int**)malloc(sizeof(int*) * height);
	for (int h = 0; h < height; h++)
	{
		map[h] = (int*)malloc(sizeof(int) * width);
	}

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			char buf;
			scanf(" %c", &buf);
			
			map[h][w] = buf == LAKE;
		}
	}

	//for (int h = 0; h < height; h++)
	//{
	//	for (int w = 0; w < width; w++)
	//	{
	//		printf("%d", map[h][w]);
	//	}
	//	printf("\n");
	//}

	int count = 0;

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			if (map[h][w]) {
				count++;
				dfs(w, h);
			}
		}
	}

	printf("%d", count);

	for (int h = 0; h < height; h++)
	{
		free(map[h]);
	}
	free(map);
}