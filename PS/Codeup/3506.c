#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int before = 3;
	int before_s_before = 2;

	if (n < 3) {
		printf("%d", n);
		return;
	}

	for (int _n = 3; _n < n; _n++)
	{
		int temp = before_s_before;
		before_s_before = before;
		before = before + temp;
	}

	printf("%d", before);
}

/*
#include<stdio.h>
#include<malloc.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int* dp = (int*)calloc(n, sizeof(int));

	dp[0] = 1;
	dp[1] = 2;

	for (int _n = 2; _n < n; _n++)
	{
		dp[_n] = dp[_n - 1] + dp[_n - 2];
	}

	printf("%d", dp[n - 1]);
}*/