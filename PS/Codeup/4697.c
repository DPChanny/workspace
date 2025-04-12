#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define MAX_HEIGHT 100
#define MIN_HEIGHT 1
#define MIN_COUNT 1

#define TRUE 1
#define FALSE 0

int** visited;
int** heights;
int n;

void dfs(int _y, int _x, int _height) {
	if (_y < 0 || _y >= n || _x < 0 || _x >= n) {
		return;
	}
	if (visited[_y][_x]) {
		return;
	}

	visited[_y][_x] = TRUE;

	if (heights[_y][_x] > _height) {
		dfs(_y + 1, _x, _height);
		dfs(_y - 1, _x, _height);
		dfs(_y, _x + 1, _height);
		dfs(_y, _x - 1, _height);
	}
}

int main(void) {
	//ũ�� �Է�
	scanf("%d", &n);

	//���� �Է�
	heights = (int**)malloc(sizeof(int*) * n);
	int max_height = MIN_HEIGHT; //���� ���� ����
	int min_height = MAX_HEIGHT; //���� ���� ����
	for (int y = 0; y < n; y++)
	{
		heights[y] = (int*)malloc(sizeof(int) * n);
		for (int x = 0; x < n; x++)
		{
			scanf("%d", &heights[y][x]);
			min_height = heights[y][x] < min_height ? heights[y][x] : min_height;
			max_height = heights[y][x] > max_height ? heights[y][x] : max_height;
		}
	}

	//Ž���� ��ġ ����
	visited = (int**)malloc(sizeof(int*) * n);
	for (int _n = 0; _n < n; _n++)
	{
		visited[_n] = (int*)calloc(n, sizeof(int));
	}

	//���� ���� ������ ���� ����
	int max_count = MIN_COUNT;
	for (int _height = min_height; _height < max_height + 1; _height++)
	{
		//������ ���� ����
		int count = 0;

		//������ ���� ���� Ž��
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (visited[y][x]) continue;
				if (heights[y][x] > _height) {
					dfs(y, x, _height);
					count++;
				}
			}
		}
		
		//���� ���� ������ ���� ���� ������Ʈ
		max_count = max_count < count ? count : max_count;

		//Ž���� ��ġ �ʱ�ȭ
		for (int _n = 0; _n < n; _n++)
		{
			memset(visited[_n], FALSE, sizeof(int) * n);
		}
	}

	//���� ���� ������ ���� ���� ���
	printf("%d", max_count);

	//���� �Ҵ� ����
	for (int _n = 0; _n < n; _n++)
	{
		free(heights[_n]);
		free(visited[_n]);
	}
	free(heights);
	free(visited);

	return EXIT_SUCCESS;
}