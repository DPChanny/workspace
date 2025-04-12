#include<stdio.h>
#include<stdlib.h>

#define NC -1

typedef struct Item {
	int w, v;
} Item;

int main(void) {
	int n, w;
	scanf("%d%d", &n, &w);

	Item* items = (Item*)malloc(sizeof(Item) * n);
	for (int _n = 0; _n < n; _n++)
	{
		scanf("%d%d", &items[_n].w, &items[_n].v);
	}

	int* prices = (int*)calloc(w + 1, sizeof(int));
	for (int _w = 1; _w < w + 1; _w++)
	{
		prices[_w] = NC;
	}

	for (int _n = 0; _n < n; _n++)
	{
		for (int _w = w; _w >= 0; _w--)
		{
			if (prices[_w] != NC) {
				if (_w + items[_n].w < w + 1) {
					if (prices[_w + items[_n].w] < prices[_w] + items[_n].v) {

						prices[_w + items[_n].w] = prices[_w] + items[_n].v;
					}
				}
			}
		}
	}

	int max = 0;
	for (int _w = 0; _w < w + 1; _w++)
	{
		if (max < prices[_w]) {
			max = prices[_w];
		}
	}

	printf("%d", max);

	free(items);
	free(prices);
}
