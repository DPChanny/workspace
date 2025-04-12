#include<stdio.h>
#include<stdlib.h>

unsigned long long int** dp;

unsigned long long int count(int _i, int _n) {
	if (_i < 0 || _i > 9) {
		return 0;
	}
	if (!_n) {
		return 1;
	}

	if (!dp[_i][_n - 1]) {
		dp[_i][_n - 1] = (count(_i + 1, _n - 1) + count(_i - 1, _n - 1)) % 1000000000;
	}

	return dp[_i][_n - 1];
}

int main(void) {
	int n;
	scanf("%d", &n);

	dp = (unsigned long long int**)malloc(sizeof(unsigned long long int*) * 10);
	for (int _i = 0; _i < 10; _i++)
	{
		dp[_i] = (unsigned long long int*)calloc(n, sizeof(unsigned long long int));
	}

	unsigned long long int sum = 0;
	for (int _i = 0; _i < 9; _i++)
	{
		sum += count(_i + 1, n - 1);
	}

	printf("%llu", sum % 1000000000);

	for (int _i = 0; _i < 10; _i++)
	{
		free(dp[_i]);
	}
	free(dp);
}