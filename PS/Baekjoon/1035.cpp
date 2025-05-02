#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr char PIECE = '*';

uint8_t pieces = 0;

bool visit[5][5][5];

typedef struct state {
  uint8_t pieces[5];
} state;

bool check_finished(const bool const (*map)[5]) {
  bool copy[5][5];
  for (uint8_t _y = 0; _y < 5; _y++)
    for (uint8_t _x = 0; _x < 5; _x++)
      copy[_y][_x] = map[_y][_x];

  uint8_t count = 0;

  bool flag = false;

  queue<pair<uint8_t, uint8_t>> q;

  for (uint8_t _y = 0; _y < 5; _y++) {
    for (uint8_t _x = 0; _x < 5; _x++)
      if (copy[_y][_x]) {
        q.emplace(_y, _x);
        copy[_y][_x] = false;
        flag = true;
        break;
      }
    if (flag)
      break;
  }

  while (!q.empty()) {
    count++;
    uint8_t _y = q.front().first;
    uint8_t _x = q.front().second;
    q.pop();
    if (_y > 0 && copy[_y - 1][_x]) {
      q.emplace(_y - 1, _x);
      copy[_y - 1][_x] = false;
    }
    if (_y < 4 && copy[_y + 1][_x]) {
      q.emplace(_y + 1, _x);
      copy[_y + 1][_x] = false;
    }
    if (_x > 0 && copy[_y][_x - 1]) {
      q.emplace(_y, _x - 1);
      copy[_y][_x - 1] = false;
    }
    if (_x < 4 && copy[_y][_x + 1]) {
      q.emplace(_y, _x + 1);
      copy[_y][_x + 1] = false;
    }
  }

  return pieces == count;
}

int main(void) {
  char buffer;

  state initial_state;

  for (uint8_t _y = 0; _y < 5; _y++) {
    for (uint8_t _x = 0; _x < 5; _x++)
      if (getchar() == PIECE)
        initial_state.pieces[pieces++] = _y * 5 + _x;
    getchar();
  }

  uint64_t size;
  uint32_t steps = 0;

  queue<state> q;
  q.push(initial_state);

  while (!q.empty()) {
    size = q.size();
    for (uint64_t _s = 0; _s < size; _s++) {
      bool map[5][5] = {false};
      const state current_state = q.front();
      q.pop();
      for (uint8_t _p = 0; _p < pieces; _p++)
        map[current_state.pieces[_p] / 5][current_state.pieces[_p] % 5] = true;

      if (check_finished(map)) {
        cout << steps;
        return 0;
      }

      for (uint8_t _p = 0; _p < pieces; _p++) {
        uint8_t _y = current_state.pieces[_p] / 5;
        uint8_t _x = current_state.pieces[_p] % 5;
        if (_y > 0 && !map[_y - 1][_x] && !visit[_p][_y - 1][_x]) {
          visit[_p][_y - 1][_x] = true;
          state new_state = current_state;
          new_state.pieces[_p] -= 5;
          q.push(new_state);
        }
        if (_y < 4 && !map[_y + 1][_x] && !visit[_p][_y + 1][_x]) {
          visit[_p][_y + 1][_x] = true;
          state new_state = current_state;
          new_state.pieces[_p] += 5;
          q.push(new_state);
        }
        if (_x > 0 && !map[_y][_x - 1] && !visit[_p][_y][_x - 1]) {
          visit[_p][_y][_x - 1] = true;
          state new_state = current_state;
          new_state.pieces[_p]--;
          q.push(new_state);
        }
        if (_x < 4 && !map[_y][_x + 1] && !visit[_p][_y][_x + 1]) {
          visit[_p][_y][_x + 1] = true;
          state new_state = current_state;
          new_state.pieces[_p]++;
          q.push(new_state);
        }
      }
    }
    steps++;
  }

  cout << "not found";
}