#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;
	int* ns;

	scanf("%d", &n);

	ns = (int*)malloc(sizeof(int) * (n + 2));
	for (int i = 1; i < n + 1; i++) scanf(" %d", &ns[i]);
	ns[0] = ns[n];
	ns[n + 1] = ns[1];

	int q = n;
	int p = 0;
	int f0 = 0;

	for (int i = 1; i < n + 1; i++)
	{
		int _f0 = !(ns[i] == ns[i - 1] + 1 || ns[i] == ns[i + 1] - 1);
		if (_f0 != f0) {
			if (f0 == 1) {
				q = i - 1;
			}
			else {
				p = i;
			}
		}
		f0 = _f0;
	}

	printf("%d\n%d %d\n%d\n", ns[p] % n, n - (n + q - p) % n, n, n - q);
}