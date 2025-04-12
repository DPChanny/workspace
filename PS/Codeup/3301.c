#include<stdio.h>

int main(void) {
	int change = 0;
	scanf("%d", &change);

	int count = 0;

	count += change / 50000;
	change %= 50000;
	count += change / 10000;
	change %= 10000;
	count += change / 5000;
	change %= 5000;
	count += change / 1000;
	change %= 1000;
	count += change / 500;
	change %= 500;
	count += change / 100;
	change %= 100;
	count += change / 500;
	change %= 500;
	count += change / 100;
	change %= 100;
	count += change / 50;
	change %= 50;
	count += change / 10;
	change %= 10;

	printf("%d", count);
}