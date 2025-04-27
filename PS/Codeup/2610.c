#include<stdio.h>

char arr[10][10];

void fill(int _x, int _y) {
	if (_x > 9 || _x < 0 || _y > 9 || _y < 0) {
		return;
	}
	if (arr[_y][_x] == '*') {
		return;
	}
	arr[_y][_x] = '*';
	fill(_x + 1, _y);
	fill(_x - 1, _y);
	fill(_x, _y + 1);
	fill(_x, _y - 1);
}

int main(void) {
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			arr[y][x] = getchar();
		}
		getchar();
	}

	int x;
	int y;
	scanf("%d %d", &x, &y);
	fill(x, y);

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			printf("%c", arr[y][x]);
		}
		printf("\n");
	}

	return 0;
}