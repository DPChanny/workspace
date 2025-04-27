#include<stdio.h>
#include<stdlib.h>

#define WIDTH 19
#define HEIGHT 19

#define X 0
#define Y 1

int board[HEIGHT][WIDTH];

//���� ������ ���� ���
int dir_vectors[4][6][2] = {
	//���� ����
	{ {-2, -2}, {-1, -1}, {1, 1}, {2, 2}, {-3, -3}, {3, 3} },
	//���� ����
	{ {-2, 2}, {-1, 1}, {1, -1}, {2, -2}, {-3, 3 }, {3, -3} },
	//y�� ����
	{ {-2, 0}, {-1, 0}, {1, 0}, {2, 0}, {-3, 0}, {3, 0 } },
	//x�� ����
	{ {0, -2}, {0, -1}, {0, 1}, {0, 2}, {0, -3}, {0, 3} } };

//�ش� ��ǥ�� _team ���ڿ� ���� ���� �ٵ� ���� �ִ��� Ȯ��
int get_board_value(int _x, int _y, int _team) {
	if (_x < 0 || _x > WIDTH - 1 || _y < 0 || _y > HEIGHT - 1) {
		return 0;
	}
	return board[_y][_x] == _team;
}

int main(void) {
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			scanf("%d", &board[y][x]);
		}
	}

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (!board[y][x]) {
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int sum = 0;
				for (int j = 0; j < 4; j++)
				{
					sum += get_board_value(x + dir_vectors[i][j][X], y + dir_vectors[i][j][Y], board[y][x]);
				}
				//printf("sum: %d\n", sum);
				if (sum == 4 && 
					!get_board_value(x + dir_vectors[i][4][X], y + dir_vectors[i][4][Y], board[y][x]) &&
					!get_board_value(x + dir_vectors[i][5][X], y + dir_vectors[i][5][Y], board[y][x])) {
					printf("%d\n", board[y][x]);
					printf("%d %d", y + dir_vectors[i][0][Y] + 1, x + dir_vectors[i][0][X] + 1);
					return;
				}
			}
		}
	}

	printf("0");
}