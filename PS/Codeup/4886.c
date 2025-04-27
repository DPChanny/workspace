#include<stdio.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

void E(int* _bottle) {
	*_bottle = 0;
}

void F(int* _bottle, int _amount_bottle) {
	*_bottle = _amount_bottle;
}

void M(int* _from, int* _to, int _amount_from, int _amount_to) {
	int left_to = _amount_to - *_to;
	if (left_to >= *_from) {
		*_to += *_from;
		*_from = 0;
	}
	else {
		*_to = _amount_to;
		*_from -= left_to;
	}
}

int main(void) {
	int amount_a, amount_b, last_a, last_b;
	scanf("%d%d%d%d", &amount_a, &amount_b, &last_a, &last_b);

	if (last_a == amount_a && last_b == amount_b) {
		printf("2");
		return;
	}

	int a = 0;
	int b = 0;

	int full_count = 0;
	int count = 0;
	int found = 0;

	do {
		if (b == amount_b) {
			E(&b);
		}
		else if (a) {
			M(&a, &b, amount_a, amount_b);
		}
		else {
			F(&a, amount_a);
		}
		
		if (!found) {
			found = a == last_a && b == last_b;
			count++;
		}
		full_count++;
	} while (a || b);

	if (found) {
		printf("%d", min(count, full_count - count));
	}
	else {
		printf("-1");
	}
}
