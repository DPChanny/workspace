#include<stdio.h>
#include<stdlib.h>

int n, m;
int** graph;
int count;

void bfs(int _target) {
	for (int _n = 0; _n < n; _n++)
	{
		if (graph[_n][_target]) {
			graph[_n][_target] = 0;
		}
	}
	count++;
	for (int _n = 0; _n < n; _n++)
	{
		if (graph[_target][_n]) {
			bfs(_n);
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	//graph[from][to]
	graph = (int**)malloc(sizeof(int*) * n);
	for (int _n = 0; _n < n; _n++)
	{
		graph[_n] = (int*)calloc(n, sizeof(int));
	}

	for (int _m = 0; _m < m; _m++)
	{
		int b1, b2;
		scanf("%d %d", &b1, &b2);
		b1--;
		b2--;
		graph[b1][b2] = 1;
		graph[b2][b1] = 1;
	}

	count = 0;
	bfs(0);

	printf("%d", count - 1);
}