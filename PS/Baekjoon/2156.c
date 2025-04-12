#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main(void) {
	int count = 0;
	scanf("%d", &count);

	int* amounts = (int*)malloc(sizeof(int) * count);
	int* amounts_cal = (int*)calloc(count, sizeof(int));

	for (int i = 0; i < count; i++)
	{
		scanf(" %d", &amounts[i]);
	}

	amounts_cal[0] = 0;
	amounts_cal[1] = amounts[1];
	amounts_cal[2] = amounts[1] + amounts[2];
	for (int i = 3; i < count; i++)
	{
		amounts_cal[i] = max(max(amounts_cal[i - 2], amounts_cal[i - 3] + amounts[i - 1]) + amounts[i], amounts_cal[i - 1]);
	}

	printf("%d", amounts_cal[count - 1]);

	free(amounts);
	free(amounts_cal);
}