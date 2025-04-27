#include<stdio.h>
#include<stdlib.h>

#include<vector>
//C++ only for vector

int** map;
int n;
std::vector<int> member_count;
int group_count;

void dfs(int _x, int _y) {
	if (_x < 0 || _x > n - 1 || _y < 0 || _y > n - 1) {
		return;
	}

	if (map[_y][_x]) {
		map[_y][_x] = 0;

		dfs(_x + 1, _y);
		dfs(_x - 1, _y);
		dfs(_x, _y + 1);
		dfs(_x, _y - 1);

		member_count[group_count]++;
	}
}

int main(void) {
	scanf("%d", &n);

	map = (int**)malloc(sizeof(int*) * n);
	for (int h = 0; h < n; h++)
	{
		map[h] = (int*)malloc(sizeof(int) * n);
	}

	for (int h = 0; h < n; h++)
	{
		getchar();
		for (int w = 0; w < n; w++)
		{
			map[h][w] = getchar() - '0';
		}
	}

	for (int h = 0; h < n; h++)
	{
		for (int w = 0; w < n; w++)
		{
			if (map[h][w]) {
				member_count.push_back(0);
				dfs(w, h);
				group_count++;
			}
		}
	}

	printf("%d\n", group_count);

	for (int i = 0; i < group_count; i++)
	{
		int id = 0;
		for (int j = id; j < member_count.size(); j++)
		{
			if (member_count[j] < member_count[id]) {
				id = j;
			}
		}
		printf("%d\n", member_count[id]);
		member_count.erase(member_count.begin() + id);
	}

	for (int h = 0; h < n; h++)
	{
		free(map[h]);
	}
	free(map);
}