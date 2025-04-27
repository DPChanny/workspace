#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int* list = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}


	long long maxSum = -9223372036854775807;
	long long curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum += list[i];
		if (list[i] > curSum) {
			curSum = list[i];
		}
		if (curSum > maxSum){
			maxSum = curSum;
		}
	}

	printf("%lld\n", maxSum);
}