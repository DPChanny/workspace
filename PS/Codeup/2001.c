#include<stdio.h>

int main(void) {
	int pasta[3] = { 0, };
	int juice[2] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		scanf(" %d", &pasta[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		scanf(" %d", &juice[i]);
	}

	int min_pasta = pasta[0];
	for (int i = 1; i < 3; i++)
	{
		if (min_pasta > pasta[i]) {
			min_pasta = pasta[i];
		}
	}
	int min_juice = juice[0];
	if (juice[1] < min_juice) {
		min_juice = juice[1];
	}

	printf("%.1f", (float)(min_juice + min_pasta) * 1.1f);
}