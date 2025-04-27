#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int width = 0;
	int height = 0;

	scanf("%d %d", &height, &width);

	int** board = (int**)malloc(sizeof(int*) * height);
	for (int i = 0; i < height; i++)
	{
		board[i] = (int*)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			char buf = '\0';
			scanf(" %c", &buf);
			board[i][j] = buf == 'B';
		}
	}

	int count = 2147483647;

	for (int i = 0; i <= height - 8; i++)
	{
		for (int j = 0; j <= width - 8; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int count_buf = 0;
				int last_board_piece_ver = k;
				for (int _height = i; _height < i + 8; _height++)
				{
					int last_board_piece_hor = last_board_piece_ver;
					for (int _width = j; _width < j + 8; _width++)
					{
						if (board[_height][_width] == last_board_piece_hor)
						{
							count_buf++;
						}
						last_board_piece_hor = !last_board_piece_hor;
					}
					last_board_piece_ver = !last_board_piece_ver;
				}

				if (count_buf < count)
				{
					count = count_buf;
				}
			}
		}
	}

	printf("%d", count);

	return 0;
}