#include<stdio.h>
#include<stdlib.h>

int n, s;
int* ns;

int dfs(int _n, int _s, int _c) {
	if (_n == n ) {
		if (_c) {
			if (_s == s) {
				return 1;
			}
		}
		return 0;
	}

	return
		dfs(_n + 1, _s + ns[_n], 1) +
		dfs(_n + 1, _s, _c);
}

int main(void) {
	scanf("%d%d", &n, &s);

	ns = (int*)malloc(sizeof(int) * n);
	for (int _n = 0; _n < n; _n++)
	{
		scanf("%d", &ns[_n]);
	}

	printf("%d", dfs(0, 0, 0));
}