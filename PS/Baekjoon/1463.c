#include<stdio.h>

int make_1(int n);
int min(int a, int b);

int main(void) {
	int n = 0;
	scanf_s("%d", &n);
	printf("%d", make_1(n));
}

/*
int make_1(int n) {
	if (n == 1) {
		return 0;
	}
	if (n % 2 == 0) {
		if (n % 3 == 0) {
			return min(min(make_1(n / 2), make_1(n - 1)), make_1(n / 3)) + 1;
		}
		else {
			return min(make_1(n / 2), make_1(n - 1)) + 1;
		}
	}
	else if (n % 3 == 0) {
		return min(make_1(n / 3), make_1(n - 1)) + 1;
	}
	else {
		return make_1(n - 1) + 1;
	}
}
*/

/*
n�� 3���� ������ �������� �ʾƵ� n/3�� ������ n%3�� ���ϸ� n�� 3���� ������ �������� n%3��ŭ ���Ͱ� ����.
���� ���μ����� ��� ������ 2, 3���� �ݺ��ϴ� 1, 2, 3 �� ������ �׿� ���� ���� ��ȯ�� �������� ���Ѵ�.
*/


int make_1(int n) {
	if (n > 3) {
		return min(make_1(n / 3) + n % 3, make_1(n / 2) + n % 2) + 1;
	}

	switch (n) {
		case 1: return 0;
		case 2: return 1;
		case 3: return 1;
	}
}

int min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}