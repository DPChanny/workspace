#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n_count;
	int* nums;
	int a_count;

	scanf("%d", &n_count);

	nums = (int*)malloc(sizeof(int) * n_count);

	for (int i = 0; i < n_count; i++)
	{
		scanf(" %d", &nums[i]);
	}

	scanf(" %d", &a_count);

	for (int i = 0; i < a_count; i++)
	{
		int n_find;
		scanf("%d", &n_find);

		int left = 0;
		int right = n_count - 1;
		int is_found = 0;
		while (right >= left) {
			int middle = (right + left) / 2;
			if (nums[middle] == n_find) {
				printf("%d\n", middle + 1);
				is_found = 1;
				break;
			}
			if (nums[middle] > n_find) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		if (!is_found) {
			printf("-1\n");
		}
	}
}