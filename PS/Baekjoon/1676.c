#include<stdio.h>
#include<math.h>

int main(void) {
	int n = 0;
	scanf("%d", &n);

	int count = 0;

	while (n >= 5) {
		count += n / 5;
		n /= 5;
	}

	printf("%d", count);
}