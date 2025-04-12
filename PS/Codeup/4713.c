#include<stdio.h>
#include<stdlib.h>

#define BLOOM 0
#define FALL 1

int main(void) {
	int f_count;
	int** flowers;

	scanf("%d", &f_count);

	flowers = (int**)malloc(sizeof(int*) * f_count);

	for (int i = 0; i < f_count; i++)
	{
		int buf_1_1, buf_1_2;
		int buf_2_1, buf_2_2;
		scanf(" %d %d %d %d", &buf_1_1, &buf_1_2, &buf_2_1, &buf_2_2);
		flowers[i] = (int*)malloc(sizeof(int) * 2);
		flowers[i][BLOOM] = (buf_1_1 * 100) + buf_1_2;
		flowers[i][FALL] = (buf_2_1 * 100) + buf_2_2;
	}

	int start = 301;
	int end = 1130;
	int count = 0;
	int last_fall = 0;

	while (start <=  end) {
		int found = 0;
		for (int i = 0; i < f_count; i++)
		{
			if (flowers[i][BLOOM] <= start) {
				if (flowers[i][FALL] > last_fall)
				{
					last_fall = flowers[i][FALL];
					found = 1;
				}
			}
		}
		if (!found)
		{
			printf("0");
			return;
		}
		count++;
		start = last_fall;
	}

	printf("%d", count);
}
