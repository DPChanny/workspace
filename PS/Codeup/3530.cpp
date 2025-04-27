#include<iostream>
#include<vector>

using namespace std;

typedef struct Blank
{
	int x, y;
	vector<int> possible;

	Blank(int _x, int _y, vector<int> _possible) {
		x = _x;
		y = _y;
		possible = _possible;
	}
} Blank;

vector<Blank> blanks;

int board[9][9];

Blank generate_blank(int _x, int _y) {
	vector<int> possible;
	for (int i = 1; i <= 9; i++)
	{
		bool flag = false;
		for (int x = 0; x < 9; x++)
		{
			if (board[_y][x] == i) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}

		for (int y = 0; y < 9; y++)
		{
			if (board[y][_x] == i) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}

		for (int y = (_y / 3) * 3; y < (_y / 3) * 3 + 3; y++)
		{
			for (int x = (_x / 3) * 3; x < (_x / 3) * 3 + 3; x++)
			{
				if (board[y][x] == i) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			continue;
		}

		possible.push_back(i);
	}

	return Blank(_x, _y, possible);
}

void fill_blank(int _n) {
	if (_n == blanks.size()) {
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				cout << board[y][x] << " ";
			}
			cout << endl;
		}
		exit(EXIT_SUCCESS);
	}

	for (int i = 0; i < blanks[_n].possible.size(); i++)
	{
		bool flag = false;
		for (int x = 0; x < 9; x++)
		{
			if (board[blanks[_n].y][x] == blanks[_n].possible[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}

		for (int y = 0; y < 9; y++)
		{
			if (board[y][blanks[_n].x] == blanks[_n].possible[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}

		for (int y = (blanks[_n].y / 3) * 3; y < (blanks[_n].y / 3) * 3 + 3; y++)
		{
			for (int x = (blanks[_n].x / 3) * 3; x < (blanks[_n].x / 3) * 3 + 3; x++)
			{
				if (board[y][x] == blanks[_n].possible[i]) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			continue;
		}

		board[blanks[_n].y][blanks[_n].x] = blanks[_n].possible[i];
		fill_blank(_n + 1);
	}

	board[blanks[_n].y][blanks[_n].x] = 0;
}

int main(void) {
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (!board[y][x]) {
				blanks.push_back(generate_blank(x, y));
			}
		}
	}

	fill_blank(0);

	cout << "Not Possible";
}