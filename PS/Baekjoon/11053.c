#include<stdio.h>
#include<stdlib.h>

int get_length(int* _nums, int* _nums_cal, int _n);

int main(void) {
	int count = 0;
	scanf("%d", &count);

	int* nums = (int*)malloc(sizeof(int) * count);
	int* nums_cal = (int*)calloc(count, sizeof(int));

	for (int i = 0; i < count; i++)
	{
		scanf(" %d", &nums[i]);
	}

	int max = 0;
	for (int i = 0; i < count; i++)
	{
		int n = get_length(nums, nums_cal, i);
		if (n > max) {
			max = n;
		}
	}

	printf("%d", max);
}

int get_length(int* _nums, int* _nums_cal, int _n) {
	if (_nums_cal[_n] == 0) {
		int max = 0;
		for (int i = 0; i < _n; i++)
		{
			if (_nums[_n] > _nums[i]) {
				int n = get_length(_nums, _nums_cal, i);
				if (n > max) {
					max = n;
				}
			}
		}

		_nums_cal[_n] = max + 1;
	}

	return _nums_cal[_n];
}