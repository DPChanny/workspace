#include<stdio.h>
#include<stdlib.h>

int count = 0;
//queen[i]: i�� ���� �� �ε���
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
		//i�� �� ��ġ ���� ����
		int flag = 0;
		//j��
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