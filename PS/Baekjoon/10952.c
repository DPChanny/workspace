#include<stdio.h>

int main(void) {
	int n1 = 0;
	int n2 = 0;

	scanf(" %d %d", &n1, &n2);
	while (n1 + n2 != 0) {
		printf("%d\n", n1 + n2);
		scanf(" %d %d", &n1, &n2);
	}
}