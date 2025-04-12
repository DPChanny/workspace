#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	int cur_degree;
	int tar_degree;

	scanf("%d %d", &cur_degree, &tar_degree);

	int count = 0;

	int interval = abs(tar_degree - cur_degree);
	count += interval / 10;
	interval %= 10;
	if (interval == 1 || interval == 5) count += 1;
	else if (interval == 2 || interval == 4 || interval == 6 || interval == 9) count += 2;
	else if (interval == 3 || interval == 7 || interval == 8) count += 3;

	printf("%d", count);
}

//일단 10으로 나누고 각 숫자가 되는 최소 개수를 더함