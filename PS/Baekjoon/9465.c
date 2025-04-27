#include<stdio.h>
#include<stdlib.h>

#define R 2 // row size

#define max(a,b) (((a) > (b)) ? (a) : (b)) // max macro

int main(void) 
{
	int t; // test case size
	scanf("%d", &t);

	for (int _t = 0; _t < t; _t++)
	{
		int c; // column size
		scanf("%d", &c);

		int* stickers[R], // sticker array
		   * dp[R]; // memoization array, dp[_r][0] : dummy
		
		for (int _r = 0; _r < R; _r++)
		{
			stickers[_r] = (int*)malloc(sizeof(int) * c);
			dp[_r] = (int*)calloc(c + 1, sizeof(int));

			for (int _c = 0; _c < c; _c++)
				scanf("%d", &stickers[_r][_c]);

			dp[_r][1] = stickers[_r][0];
		}

		for (int _c = 2; _c < c + 1; _c++)
		{
			for (int _r = 0; _r < R; _r++)
			{
				dp[_r][_c] = max(max(dp[_r][_c - 2], dp[!_r][_c - 2]), dp[!_r][_c - 1]) + stickers[_r][_c - 1];
			}
		}

		printf("%d\n", max(dp[0][c], dp[1][c]));

		for (int _r = 0; _r < R; _r++) 
		{
			free(stickers[_r]);
			free(dp[_r]);
		}
	}
}
