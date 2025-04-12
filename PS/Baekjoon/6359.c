#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		int roomCount;
		scanf("%d", &roomCount);
		
		for (int j = 1; j * j <= roomCount; j++)
		{
			count++;
		}

		printf("%d\n", count);
	}
}