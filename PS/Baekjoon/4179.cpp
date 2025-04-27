#include<iostream>
#include<queue>

using namespace std;

constexpr char WALL = '#';
constexpr char VOID = '.';
constexpr char FIRE = 'F';
constexpr char BODY = 'J';

char map[1000][1000];
int y_size, x_size;

struct Vector {
	int y, x;
};

static bool check_position(Vector _position) {
	return
		_position.y + 1 > 0 && _position.y < y_size &&
		_position.x + 1 > 0 && _position.x < x_size &&
		map[_position.y][_position.x] != WALL;
}

static bool check_fire_position(Vector _position) {
	return 
		check_position(_position) && 
		map[_position.y][_position.x] != FIRE;
}

static bool check_body_position(Vector _position) {
	return
		check_fire_position(_position) && 
		map[_position.y][_position.x] != BODY;
}

int main(void) {
	bool flag(false);
	int queue_size, trial(0);
	Vector position_buffer;
	char map_buffer;
	cin >> y_size >> x_size;
	queue<Vector> next_body_positions, next_fire_positions;

	for (int y(0); y < y_size; y++) {
		getchar();
		for (int x(0); x < x_size; x++) {
			map_buffer = getchar();
			map[y][x] = VOID;
			if (map_buffer == FIRE) next_fire_positions.push({ y, x });
			if (map_buffer == BODY) next_body_positions.push({ y, x });
			if (map_buffer == WALL) map[y][x] = WALL;
		}
	}

	while (!next_body_positions.empty()) {
		trial++;

		queue_size = next_fire_positions.size();
		for (int i(0); i < queue_size; i++) {
			position_buffer = next_fire_positions.front(); next_fire_positions.pop();
			if (map[position_buffer.y][position_buffer.x] == FIRE) continue;
			map[position_buffer.y][position_buffer.x] = FIRE;

			if (check_fire_position({ position_buffer.y + 1, position_buffer.x })) next_fire_positions.push({ position_buffer.y + 1, position_buffer.x });
			if (check_fire_position({ position_buffer.y - 1, position_buffer.x })) next_fire_positions.push({ position_buffer.y - 1, position_buffer.x });
			if (check_fire_position({ position_buffer.y, position_buffer.x + 1 })) next_fire_positions.push({ position_buffer.y, position_buffer.x + 1 });
			if (check_fire_position({ position_buffer.y, position_buffer.x - 1 })) next_fire_positions.push({ position_buffer.y, position_buffer.x - 1 });
		}

		queue_size = next_body_positions.size();
		for (int i(0); i < queue_size; i++) {
			position_buffer = next_body_positions.front(); next_body_positions.pop();
			if (map[position_buffer.y][position_buffer.x] == FIRE) continue;
			if (map[position_buffer.y][position_buffer.x] == BODY) continue;
			map[position_buffer.y][position_buffer.x] = BODY;

			if (position_buffer.y + 1 == y_size || position_buffer.x + 1 == x_size || position_buffer.y == 0 || position_buffer.x == 0){
				flag = true;
				break;
			}

			if (check_body_position({ position_buffer.y + 1, position_buffer.x })) next_body_positions.push({ position_buffer.y + 1, position_buffer.x });
			if (check_body_position({ position_buffer.y - 1, position_buffer.x })) next_body_positions.push({ position_buffer.y - 1, position_buffer.x });
			if (check_body_position({ position_buffer.y, position_buffer.x + 1 })) next_body_positions.push({ position_buffer.y, position_buffer.x + 1 });
			if (check_body_position({ position_buffer.y, position_buffer.x - 1 })) next_body_positions.push({ position_buffer.y, position_buffer.x - 1 });
		}
	}

	if (flag) cout << trial;
	else cout << "IMPOSSIBLE";
}
