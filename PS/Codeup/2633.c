#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int count;
	int* nums;
	int n;

	scanf("%d %d", &count, &n);

	nums = (int*)malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		scanf(" %d", &nums[i]);
	}

	for (int i = 0; i < count; i++)
	{
		if (nums[i] >= n) {
			printf("%d", i + 1);
			return;
		}
	}
	printf("%d", count + 1);
}