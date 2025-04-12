#include<iostream>
#include<queue>

#define RAW_TOMATO 0
#define TOMATO 1
#define VOID -1

typedef struct Point2 {
	int x;
	int y;
	int depth;
};

using namespace std;

int main(void) {
	int x_size, y_size;

	cin >> x_size >> y_size;

	queue<Point2> queue;

	//tomatoes[y][x];
	int** tomatoes = new int* [y_size];
	for (int _y = 0; _y < y_size; _y++)
	{
		tomatoes[_y] = new int [x_size];
		for (int _x = 0; _x < x_size; _x++)
		{
			cin >> tomatoes[_y][_x];
			if (tomatoes[_y][_x] == TOMATO) {
				queue.push({ _x + 1, _y, 1 });
				queue.push({ _x - 1, _y, 1 });
				queue.push({ _x, _y + 1, 1 });
				queue.push({ _x, _y - 1, 1 });
			}
		}
	}

	int last_depth = 0;

	while (queue.size())
	{
		Point2 point = queue.front();
		queue.pop();
		if (point.y < 0 || point.y >= y_size ||
			point.x < 0 || point.x >= x_size) {
			continue;
		}
		if (tomatoes[point.y][point.x] == VOID) {
			continue;
		}
		if (tomatoes[point.y][point.x] == TOMATO) {
			continue;
		}

		tomatoes[point.y][point.x] = TOMATO;

		last_depth = point.depth;

		queue.push({ point.x + 1, point.y, point.depth + 1 });
		queue.push({ point.x - 1, point.y, point.depth + 1 });
		queue.push({ point.x, point.y + 1, point.depth + 1 });
		queue.push({ point.x, point.y - 1, point.depth + 1 });
	}

	bool flag = false;
	for (int _y = 0; _y < y_size; _y++)
	{
		for (int _x = 0; _x < x_size; _x++)
		{
			if (tomatoes[_y][_x] == RAW_TOMATO) {
				flag = true;
			}
		}
	}
	if (flag) {
		cout << "-1";
	}
	else {
		cout << last_depth;
	}

	return EXIT_SUCCESS;
}