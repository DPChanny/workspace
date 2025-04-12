#include<stdio.h>
#include<stdlib.h>

int n;

int dfs(int _n, int _b) {
	if (_n == n - 1) {
		return 1;
	}

	int count = dfs(_n + 1, 1);
	if (_b) {
		count += dfs(_n + 1, 0);
	}

	return count;
}

int main(void) {
	scanf("%d", &n);

	printf("%d", dfs(0, 0) + dfs(0, 1));
}