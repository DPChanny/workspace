#include<stdio.h>
#include<stdlib.h>

int n;

int dfs(int _n, int _t) {
	if (_n > n) {
		return 0;
	}
	if (_n == n) {
		return 1;
	}

	int count =
		dfs(_n + 1, _t - 1) +
		dfs(_n + 2, _t - 1);
	if (_t < 1) {
		count += dfs(_n + 3, 2);
	}

	return count;
}

int main(void) {
	scanf("%d", &n);

	printf("%d", dfs(1, 0) +
		dfs(2, 0) + dfs(3, 2));
}