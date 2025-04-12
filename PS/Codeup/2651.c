#include<stdio.h>
#include<stdlib.h>

int n, k;

int dfs(int _n, int _k) {
	if (n == _n) {
		if (k == _k) {
			return 1;
		}
		else {
			return 0;
		}
	}

	return
		dfs(_n + 1, _k) +
		dfs(_n + 1, _k + 1);
}

int main(void) {
	scanf("%d%d", &n, &k);

	printf("%d", dfs(1, 0) + dfs(1, 1));
}