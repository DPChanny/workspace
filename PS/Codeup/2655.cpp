#include<stdio.h>
#include<math.h>

int main(void) {
	double start = -999;
	double end = 999;
	double middle = (start + end) / 2;
	double a, b;
	scanf("%lf%lf", &a, &b);
	while (end - start > 0.0001) {
		if (a * middle + b > 0) {
			end = middle;
		}
		else if (a * middle + b < 0) {
			start = middle;
		}
		else {
			printf("%.4lf", middle);
			return;
		}

		middle = (start + end) / 2;
	}
	printf("%.4lf", middle);
}