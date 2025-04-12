#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int target = 0;

	scanf("%d", &target);

	int constructer = 0;

	for (int i = 1; i < target; i++)
	{
		constructer = i;

		int count = 0;
		int i_back_up = i;
			
		while (i_back_up != 0)
		{
			i_back_up = i_back_up / 10;
			count++;
		}

		for (int j = 1; j <= count; j++)
		{
			constructer += (i / (int) pow(10, (j - 1))) % 10;
		}

		if (constructer == target)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("0");
	return 0;
}