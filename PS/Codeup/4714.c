#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define TRUE 1
#define FALSE 0

int n; //학생수
int** graph; //키 관계도
int* visited;

int dfs(int _from) {
	if (visited[_from] == 1) {
		return 0;
	}
	visited[_from] = 1;
	int count = 1;
	for (int _n = 0; _n < n; _n++)
	{
		if (graph[_from][_n]) {
			count += dfs(_n);
		}
	}
	return count;
}

int dfs_reverse(int _to) {
	if (visited[_to] == 2) {
		return 0;
	}
	visited[_to] = 2;
	int count = 1;
	for (int _n = 0; _n < n; _n++)
	{
		if (graph[_n][_to]) {
			count += dfs_reverse(_n);
		}
	}
	return count;
}

int main(void) {
	//비교횟수
	int m;
	scanf("%d %d", &n, &m);

	//graph[from][to]
	graph = (int**)malloc(sizeof(int*) * n);
	for (int from = 0; from < n; from++)
	{
		graph[from] = (int*)calloc(n, sizeof(int));
	}

	//그래프 입력
	for (int _m = 0; _m < m; _m++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		graph[--from][--to] = TRUE;
	}

	//키 순서 판별 가능 학생수
	int count = 0;

	visited = (int*)calloc(n, sizeof(int));
	for (int _n = 0; _n < n; _n++)
	{
		//_n번째 학생 보다 키가 작은 학생수
		int shorter = dfs_reverse(_n) - 1;
		//_n번째 학생 보다 키가 큰 학생수
		int taller = dfs(_n) - 1;
		if (shorter + taller  == n - 1) {
			count++;
		}

		memset(visited, 0, sizeof(int) * n);
	}

	printf("%d", count);

	for (int _n = 0; _n < n; _n++)
	{
		free(graph[_n]);
	}
	free(graph);
	free(visited);
	
	return EXIT_SUCCESS;
}