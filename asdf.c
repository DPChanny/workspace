#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

void waitEnter();

void main()
{
	const char* asdfs = "asdf";

	float time;
	int inputCount;
	char i;

	while (1)
	{
		inputCount = 0;
		i = 0;

		waitEnter();
		system("cls");

		char input;

		clock_t start = clock();
		while (1)
		{
			input = _getche();
			rewind(stdin);
			if (input != asdfs[i])
			{
				break;
			}
			i++;
			if (i >= strlen(asdfs))
			{
				i = 0;
			}
			inputCount++;
		}
		clock_t end = clock();

		time = (float)(end - start) / CLOCKS_PER_SEC;

		printf("\n걸린 시간: %f초, 입력한 asdf수: %d, 초당 입력수: %f\n", time, (int)inputCount / 4, 1 / (time / inputCount));

		waitEnter();
		system("cls");
	}
}

void waitEnter()
{
	printf("press enter to continue");
	while (1)
	{
		char input = getchar();
		rewind(stdin);
		if (input == '\n')
		{
			break;
		}
	}
}