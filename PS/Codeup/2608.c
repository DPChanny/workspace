#include<stdio.h>
#include<stdlib.h>

int n;
char* chars;

void dfs(int _n, char _c) {
	chars[_n] = _c;

	if (_n == n - 1) {
		printf("%s\n", chars);
		return;
	}

	dfs(_n + 1, 'O');
	dfs(_n + 1, 'X');
}

int main(void) {
	scanf("%d", &n);
	chars = (char*)calloc(n + 1, sizeof(char));

	dfs(0, 'O');
	dfs(0, 'X');

	free(chars);
}