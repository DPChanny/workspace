#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int card_count = 0;
	int black_jack_num = 0;

	//입력
	scanf("%d %d", &card_count, &black_jack_num);
	int* cards = (int*) malloc(sizeof(int) * card_count);

	for (int i = 0; i < card_count; i++)
	{
		scanf("%d", &cards[i]);
	}

	int current_less = 0;

	//처리
	for (int i = 0; i < card_count; i++)
	{
		for (int j = i + 1; j < card_count; j++)
		{
			for (int k = j + 1; k < card_count; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= black_jack_num)
				{
					if (black_jack_num - current_less > black_jack_num - sum)
					{
						current_less = sum;
					}
				}
			}
		}
	}

	printf("%d", current_less);

	return 0;
}