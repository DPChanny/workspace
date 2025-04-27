#include<stdio.h>
#include<stdlib.h>

int get_count(int _n);

int* counts;

int main(void) {
	int n = 0;

	scanf("%d", &n);

	counts = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		counts[i] = NULL;
	}

	printf("%d", get_count(n));
}

int get_count(int _n) {
	if (_n <= 0) {
		return 0;
	}
	switch (_n)
	{
	case 1:
		return 1;
	case 2:
		return 3;
	}

	if (counts[_n - 1] == NULL) {
		counts[_n - 1] = (get_count(_n - 1) + get_count(_n - 2) * 2) % 10007;
	}

	return counts[_n - 1];
}