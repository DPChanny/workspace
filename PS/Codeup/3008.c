#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef char bool;

#define RD_SUM 100
#define RD_COUNT 7
#define D_COUNT 9

int ds[D_COUNT];
int rds[RD_COUNT];

void dfs(int _n, int _nr, bool _fill, int _sum) {
	if (_nr == RD_COUNT) {
		if (_sum == RD_SUM) {
			for (int i = 0; i < RD_COUNT; i++)
			{
				int id = 0;
				for (int i = 0; i < RD_COUNT; i++)
				{
					if (rds[id] > rds[i]) {
						id = i;
					}
				}
				printf("%d\n", rds[id]);
				rds[id] = RD_SUM;
			}
			exit(EXIT_SUCCESS);
		}
		return;
	}

	if (D_COUNT - _n < RD_COUNT - _nr) {
		return;
	}

	if (_fill) {
		rds[_nr] = ds[_n];
		_sum += ds[_n];
	}
	dfs(_n + 1, _nr + _fill, TRUE, _sum);
	dfs(_n + 1, _nr + _fill, FALSE, _sum);
}

int main(void) {
	for (int i = 0; i < D_COUNT; i++)
	{
		scanf("%d", &ds[i]);
	}

	dfs(0, 0, TRUE, 0);
	dfs(0, 0, FALSE, 0);
}