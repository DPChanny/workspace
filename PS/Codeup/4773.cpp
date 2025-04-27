#include<iostream>
#include<queue>

#define RAW_TOMATO 0
#define TOMATO 1
#define VOID -1

typedef struct Point3 {
	int x;
	int y;
	int z;
	int depth;
};

using namespace std;

int main(void) {
	int x_size, y_size, z_size;

	cin >> x_size >> z_size >> y_size;

	queue<Point3> queue;

	//tomatoes[y][z][x];
	int*** tomatoes = new int**[y_size];
	for (int _y = 0; _y < y_size; _y++)
	{
		tomatoes[_y] = new int* [z_size];
		for (int _z = 0; _z < z_size; _z++)
		{
			tomatoes[_y][_z] = new int[x_size];
			for (int _x = 0; _x < x_size; _x++)
			{
				cin >> tomatoes[_y][_z][_x];
				if(tomatoes[_y][_z][_x] == TOMATO){
					queue.push({_x, _y, _z, 0});
					queue.push({ _x + 1, _y, _z, 1 });
					queue.push({ _x - 1, _y, _z, 1 });
					queue.push({ _x, _y + 1, _z, 1 });
					queue.push({ _x, _y - 1, _z, 1 });
					queue.push({ _x, _y, _z + 1, 1 });
					queue.push({ _x, _y, _z - 1, 1 });
				}
			}
		}
	}

	int last_depth = 0;

	while (queue.size()) 
	{
		Point3 point = queue.front();
		queue.pop();
		if (point.y < 0 || point.y >= y_size ||
			point.z < 0 || point.z >= z_size ||
			point.x < 0 || point.x >= x_size) {
			continue;
		}
		if (tomatoes[point.y][point.z][point.x] == VOID) {
			continue;
		}
		if (tomatoes[point.y][point.z][point.x] == TOMATO) {
			continue;
		}

		tomatoes[point.y][point.z][point.x] = TOMATO;

		last_depth = point.depth;

		queue.push({ point.x + 1, point.y, point.z, point.depth + 1 });
		queue.push({ point.x - 1, point.y, point.z, point.depth + 1 });
		queue.push({ point.x, point.y + 1, point.z, point.depth + 1 });
		queue.push({ point.x, point.y - 1, point.z, point.depth + 1 });
		queue.push({ point.x, point.y, point.z + 1, point.depth + 1 });
		queue.push({ point.x, point.y, point.z - 1, point.depth + 1 });
	}

	bool flag = false;
	for (int _y = 0; _y < y_size; _y++)
	{
		for (int _z = 0; _z < z_size; _z++)
		{
			for (int _x = 0; _x < x_size; _x++)
			{
				if (tomatoes[_y][_z][_x] == RAW_TOMATO) {
					flag = true;
				}
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