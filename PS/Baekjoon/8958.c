#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		char buf = getchar();
		int count = 1;
		int score = 0;
		while (buf != '\n') {
			if (buf == 'O') {
				score += count++;
			}
			else {
				count = 1;
			}
			buf = getchar();
		}
		printf("%d\n", score);
	}
}