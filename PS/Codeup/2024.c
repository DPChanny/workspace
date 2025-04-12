#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_LEN 16

#define TRUE 1
#define FALSE 2
typedef unsigned char boolean;

//반복되는 단위
const char circulationUnit[][4] = { "십", "백", "천" };
//반복되지 않는 단위
const char unit[][4] = { "만", "억", "조", "경" };
//(인덱스 + 1)에 대응하는 한글
const char strNum[][4] = { "일", "이", "삼", "사", "오", "육", "칠", "팔", "구" };

char* getStrNum(char num)
{
	return strNum[num - '0' - 1];
}

void main()
{
	//입력 받은 숫자
	char num[MAX_BUF_LEN];

	//0이 아닌 숫자가 있었는지 판단
	boolean is_num = FALSE;

	if (scanf("%s", num))
	{
		for (int i = 0; i < strlen(num); i++)
		{
			//현재 자릿수
			int currentIndex = strlen(num) - i;

			if (num[i] != '0')
			{
				//숫자에 대응하는 한글 출력
				printf("%s", getStrNum(num[i]));

				//순환하는 단위 출력
				int circulationUnitIndex = currentIndex % 4 - 2;
				if (circulationUnitIndex != -1)
				{
					printf("%s", circulationUnit[abs(circulationUnitIndex)]);
				}

				is_num = TRUE;
			}
			else
			{
				if (strlen(num) == 1)
				{
					printf("영");
				}
			}

			if (currentIndex > 4)
			{
				if (is_num)
				{
					//순환하지 않는 단위 출력
					int unitIndex = currentIndex / 4;
					if (currentIndex % 4 == 1)
					{
						printf("%s", unit[unitIndex - 1]);
						is_num = FALSE;
					}
				}
			}
		}
	}
}