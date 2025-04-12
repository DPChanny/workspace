#include<stdio.h>
#include<stdlib.h>

int* dp;

int count(int _n) {
	if (!_n || _n == 1) {
		return 1;
	}

	if (!dp[_n - 1]) {
		dp[_n - 1] = (count(_n - 1) + count(_n - 2)) % 15746;;
	}

	return dp[_n - 1];
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	dp = (int*)calloc(n, sizeof(int));

	printf("%d", count(n));

	free(dp);
}