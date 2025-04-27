#include<stdio.h>
#include<stdlib.h>

#define NaN -1

int get_number_of_cases(int n);
int sum(int arr[]);

int main(void) {
	int t = 0;
	scanf("%d", &t);
	int* inputs = (int*) malloc(sizeof(int) * t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &inputs[i]);
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", get_number_of_cases(inputs[i]));
	}
}

int get_number_of_cases(int n) {
	if (n < 0) {
		return NaN;
	}
	else if (n == 0) {
		return 1;
	}
	else {
		int f1 = get_number_of_cases(n - 1);
		int f2 = get_number_of_cases(n - 2);
		int f3 = get_number_of_cases(n - 3);

		int arr[] = { f1, f2, f3 };

		return sum(arr);
	}
}

int sum(int arr[]) {
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] != NaN) {
			sum += arr[i];
		}
	}
	return sum;
}