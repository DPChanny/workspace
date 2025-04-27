#include<stdio.h>
#include<stdlib.h>

int n, k;

int dfs(int _n, int _k, int _f) {
	if (k == _k) {
		return 1;
	}
	if (n == _n) {
		if (k == _k) {
			return 1;
		}
		return 0;
	}

	int count = dfs(_n + 1, _k + _f, 0);
	if (!_f) {
		count += dfs(_n + 1, _k + _f, 1);
	}

	return count;
}

int main(void) {
	scanf("%d%d", &n, &k);

	printf("%d", dfs(0, 0, 1) + dfs(0, 0, 0));
}