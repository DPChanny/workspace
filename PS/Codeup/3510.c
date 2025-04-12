#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int* ns;
int b, n;

int dfs(int _n, int _price, int _price_before) {
	if (_price > b) {
		return _price_before;
	}
	if (_n == n) {
		return _price;
	}

	return max(dfs(_n + 1, _price + ns[_n], _price), dfs(_n + 1, _price, _price));
}

int main(void) {
	scanf("%d%d", &b, &n);
	ns = (int*)malloc(sizeof(int) * n);
	for (int _n = 0; _n < n; _n++)
	{
		scanf("%d", &ns[_n]);
	}

	printf("%d", dfs(0, 0, 0));
}