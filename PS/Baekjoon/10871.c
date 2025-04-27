#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n = 0;
	int x = 0;

	scanf("%d %d", &n, &x);

	int* nums = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &nums[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] < x) {
			printf("%d ", nums[i]);
		}
	}

	free(nums);
}