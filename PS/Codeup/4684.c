#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int count;
	int* locked;

	scanf("%d", &count);

	locked = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		scanf(" %d", &locked[i]);
	}

	int i_p;
	int i_m;
	int end = 0;
	int start = 0;
	int found_0 = 0;

	for (int i = 0; i < count; i++)
	{
		i_p = i + 1;
		if (i + 1 == count) {
			i_p = 0;
		}

		i_m = i - 1;
		if (i - 1 == -1) {
			i_m = count - 1;
		}

		int _found_0 = !(locked[i] == locked[i_m] + 1 || locked[i] == locked[i_p] - 1);
		if (_found_0 != found_0) {
			if (found_0 == 1) {
				end = i;
			}
			else {
				start = i;
			}
		}
		found_0 = _found_0;
	}

	printf("%d\n", locked[start]);
	if (start == end) {
		printf("1 %d\n", count);
	}
	else {
		if (start > end) {
			printf("%d %d\n", count - ((count - start) + end) + 1, count);
		}
		else {
			printf("%d %d\n", count - (end - start) + 1, count);
		}
	}
	printf("%d\n", count - end);
}