#include<stdio.h>
#include<stdlib.h>

#define DEBUG

int get_i_p(int _i, int _count);
int get_i_m(int _i, int _count);

int main(void) {
	int count;
	int* locked;

	scanf("%d", &count);

	locked = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		scanf(" %d", &locked[i]);
	}

	int* locked_stat = (int*)malloc(sizeof(int) * count);

	int i_p;
	int i_m;

	for (int i = 0; i < count; i++)
	{
		i_p = get_i_p(i, count);
		i_m = get_i_m(i, count);

		locked_stat[i] = locked[i] == locked[i_m] + 1 || locked[i] == locked[i_p] - 1;
	}

#ifdef DEBUG
	for (int i = 0; i < count; i++)
	{
		printf("%d ", locked_stat[i]);
	}
	printf("\n");
#endif

	int end = 0;
	int start = 0;

	int found0 = 0;
	for (int i = 0; i < count; i++)
	{
		int _found0 = locked_stat[i] == 0;
		if (_found0 != found0) {
			if (found0 == 1) {
				end = i;
			}
			else {
				start = i;
			}
		}
		found0 = _found0;
	}

#ifdef DEBUG
	printf("%d %d\n", start, end);
#endif

	if (start == end) {
		printf("0\n");
		printf("1 %d\n", count);
		printf("0\n");
	}
	else {
		printf("%d\n", locked[start]);
		if (start > end) {
			printf("%d %d\n", count - ((count - start) + end) + 1, count);
		}
		else {
			printf("%d %d\n", count - (end - start) + 1, count);
		}
		printf("%d\n", count - end);
	}
}

int get_i_p(int _i, int _count) {
	if (_i  + 1 == _count) {
		return 0;
	}
	return _i + 1;
}

int get_i_m(int _i, int _count) {
	if (_i - 1 == -1) {
		return _count - 1;
	}
	return _i - 1;
}