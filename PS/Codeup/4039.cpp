#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<queue>
//C++ only for queue

#define TRUE 1
#define FALSE 0

typedef struct NM {
	int n;
	int m;
	int depth;
} NM;

#define DIR_VECTORS_COUNT 4
NM dir_vectors[DIR_VECTORS_COUNT] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main(void) {
	int n, m;
	int** map;
	int** went;

	//입력 1
	scanf("%d %d", &n, &m);

	//동적 할당
	map = (int**)malloc(sizeof(int*) * n);
	went = (int**)malloc(sizeof(int*) * n);
	for (int _n = 0; _n < n; _n++)
	{
		map[_n] = (int*)malloc(sizeof(int) * m);
		went[_n] = (int*)calloc(m, sizeof(int));
	}

	//입력 2
	for (int _n = 0; _n < n; _n++)
	{
		for (int _m = 0; _m < m; _m++)
		{
			scanf("%d", &map[_n][_m]);
		}
	}

	std::queue<NM> queue;
	queue.push({ 0, 0, 1 });

	int flag = FALSE;

	while (queue.size()) {
		NM nm = queue.front();
		queue.pop();

		if (went[nm.n][nm.m]) {
			continue;
		}

		went[nm.n][nm.m] = TRUE;
		if (nm.n == n - 1 && nm.m == m - 1) {
			printf("%d", nm.depth);
			flag = TRUE;
			break;
		}

		for (int v = 0; v < DIR_VECTORS_COUNT; v++)
		{
			NM new_nm = { nm.n + dir_vectors[v].n, nm.m + dir_vectors[v].m, nm.depth + 1 };
			if (new_nm.n < 0 || new_nm.n > n - 1 || new_nm.m < 0 || new_nm.m > m - 1) {
				continue;
			}
			if (abs(map[nm.n][nm.m] - map[new_nm.n][new_nm.m]) > 1) {
				continue;
			}
			queue.push(new_nm);
		}
	}

	if (!flag) {
		printf("0");
	}

	//동적 할당 해제
	for (int _n = 0; _n < n; _n++)
	{
		free(map[_n]);
		free(went[_n]);
	}
	free(map);
	free(went);
}
