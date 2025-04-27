#include<stdio.h>
#include<stdlib.h>

int count = 0;
//queen[i]: i열 퀸의 행 인덱스
int* queen;
int n;

int dfs(int _n) {
	if (n == _n) {
		count++;
		if (count < 4) {
			for (int i = 0; i < n; i++)
			{
				printf("%d ", queen[i] + 1);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		//i행 퀸 배치 가능 여부
		int flag = 0;
		//j열
		for (int j = 0; j < _n; j++)
		{
			int distance = _n - j;
			if (queen[j] == i || queen[j] == i - distance || queen[j] == i + distance) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			continue;
		}
		queen[_n] = i;
		dfs(_n + 1);
	}
}

int main(void) {
	scanf("%d", &n);

	queen = (int*)calloc(n, sizeof(int));

	dfs(0);

	printf("%d", count);

	free(queen);
}