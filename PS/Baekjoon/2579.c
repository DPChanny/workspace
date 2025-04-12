#include<stdio.h>
#include<stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int get_max(int* _stairs, int** _stairs_cal, int _n, int _count);

int main(void) {
	int n = 0;
	
	scanf("%d", &n);

	int* stairs = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &stairs[i]);
	}

	int** stairs_cal = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		stairs_cal[i] = (int*)malloc(sizeof(int) * 2);
		for (int j = 0; j < 2; j++)
		{
			stairs_cal[i][j] = NULL;
		}
	}

	printf("%d", get_max(stairs, stairs_cal, n - 1, 0));

	free(stairs);
	for (int i = 0; i < n; i++)
	{
		free(stairs_cal[i]);
	}
	free(stairs_cal);

}

int get_max(int* _stairs, int** _stairs_cal, int _n, int _count) {
	if (_count < 2) {
		if (_stairs_cal[_n][_count] == NULL) {

			if (_n == 0) {
				_stairs_cal[_n][_count] =  _stairs[_n];
			}
			else if (_n == 1) {
				_stairs_cal[_n][_count] = get_max(_stairs, _stairs_cal, _n - 1, _count + 1) + _stairs[_n];
			}
			else {
				_stairs_cal[_n][_count] = max(get_max(_stairs, _stairs_cal, _n - 1, _count + 1), get_max(_stairs, _stairs_cal, _n - 2, 0)) + _stairs[_n];
			}
		}
	}
	else {
		return 0;
	}

	return _stairs_cal[_n][_count];
}