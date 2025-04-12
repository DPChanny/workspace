#include<stdio.h>

unsigned long long fibo[1000000] = { 0,1 };

int main(void) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%llu", fibo[n]);
}

/*#include<stdio.h>

//not calculated
#define NC -1
//calculated num count
#define CNC 1000000

int fibonacci(int n);

long long calculated_num[CNC] = { 0, };

int main(void) {
	for (int i = 0; i < CNC; i++)
	{
		calculated_num[i] = NC;
	}
	int n = 0;
	scanf("%d", &n);
	printf("%d", fibonacci(n));
}

int fibonacci(int n) {
	if (calculated_num[n] != NC) {
		return calculated_num[n];
	}
	if (n == 0 || n == 1) {
		calculated_num[n] = n;
		return n;
	}
	else {
		int f1 = fibonacci(n - 1);
		int f2 = fibonacci(n - 2);
		calculated_num[n] = f1 + f2;
		return  f1 + f2;
	}
}*/