#include<stdio.h>
#include<stdlib.h>

#define NONE ' '
#define PLUS '+'
#define MINUS '-'

int n;
char* symbols;

void dfs(int _n, int _symbol) {

	symbols[_n] = _symbol;

	if (_n + 1 == n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i + 1;
			int carry = j;
			while (symbols[j] == NONE && j < n) {
				carry = carry * 10 + ++j;
			}

			if (symbols[i] == PLUS) {
				sum += carry;
			}
			if (symbols[i] == MINUS) {
				sum -= carry;
			}
			i = j - 1;
		}
		if (!sum) {

			printf("1");
			for (int i = 1; i < n; i++)
			{
				printf("%c%d", symbols[i], i + 1);
			}
			printf("\n");
		}
		return;
	}

	dfs(_n + 1, NONE);
	dfs(_n + 1, PLUS);
	dfs(_n + 1, MINUS);
}

int main(void) {
	scanf("%d", &n);

	symbols = (char*)calloc(n, sizeof(char));
	dfs(0, PLUS);

	free(symbols);
}