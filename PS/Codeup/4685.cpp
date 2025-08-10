#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define DEBUG

using namespace std;

typedef struct Code {
  int value;            // 占쌘듸옙 占쏙옙
  int order;            // 占쌉뤄옙 占쏙옙占쏙옙
  vector<Code*> codes;  // 占싱듸옙 占쏙옙占쏙옙 占쌘듸옙
  bool visit;
  Code* before;
} Code;

bool compare(Code* a, Code* b) {
  return a->value < b->value;
}

int main(void) {
  // 占쌘듸옙 占쏙옙占쏙옙, 占쌘듸옙 占쏙옙占쏙옙
  int n, k;
  cin >> n >> k;

  // 占쌘듸옙 占쏙옙占쏙옙占쏙옙 占쏙옙환 占쌉뤄옙
  Code** codes = new Code*[n];
  for (int _n = 0; _n < n; _n++) {
    Code* code = new Code;

    getchar();
    int value = 0;
    for (int l = 0; l < k; l++) {
      value = value << 1;
      value += getchar() - '0';
    }
    code->value = value;
    code->order = _n;
    code->visit = false;
    code->before = NULL;
    codes[_n] = code;
  }

  int buf1, buf2;
  cin >> buf1 >> buf2;
  buf1--;
  buf2--;
  Code* start_code = codes[buf1];
  Code* end_code = codes[buf2];

  queue<Code*> queue;
  start_code->visit = true;
  queue.push(start_code);

  // 占쌘듸옙 占쏙옙占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙
  sort(codes, codes + n, compare);

#ifdef DEBUG
  for (int _n = 0; _n < n; _n++) {
    cout << "order: " << codes[_n]->order << endl;
    cout << "value: " << codes[_n]->value << endl;
  }
#endif

  for (int _n = 0; _n < n; _n++) {
    // 占쌩븝옙 占싱듸옙 占쏙옙占쏙옙 占쌘듸옙 占쏙옙占신몌옙 占쏙옙占쏙옙 temp
    int temp = codes[_n]->value;
    for (int _k = 0; _k < k; _k++) {
      //_k占쏙옙째 占쏙옙트占쏙옙 1 占싱몌옙 占쏙옙占쏙옙
      if (temp & 1) {
        // 占쏙옙占쏙옙 占쌘드에占쏙옙 _k 占쏙옙째 占쏙옙트占쏙옙 0占쏙옙占쏙옙 占쌕뀐옙
        int target = codes[_n]->value - (1 << _k);
        // 占싱븝옙탐占쏙옙占쏙옙占쏙옙 target 占쌘듸옙 탐占쏙옙
        int _start = 0;
        int _end = _n - 1;
        while (_start != _end) {
          int middle = (_start + _end) / 2;

          if (codes[middle]->value >= target) {
            _end = middle;
          } else {
            _start = middle + 1;
          }
        }
        if (codes[_start]->value == target) {
          codes[_n]->codes.push_back(codes[_start]);
          codes[_start]->codes.push_back(codes[_n]);
        }
      }
      temp = temp >> 1;
    }
  }

#ifdef DEBUG
  cout << endl;
  for (int _n = 0; _n < n; _n++) {
    cout << "order: " << codes[_n]->order << endl;
    for (int i = 0; i < codes[_n]->codes.size(); i++) {
      cout << "connection: " << codes[_n]->codes[i]->order << endl;
    }
  }
#endif

  // BFS占쏙옙 before 占쏙옙占쏙옙占쏙옙 占쏙옙占쏙옙 占쏙옙 visit 占쏙옙占쏙옙占쏙옙트
  while (queue.size()) {
    Code* code = queue.front();
    queue.pop();

#ifdef DEBUG
    cout << endl;
    cout << "order: " << code->order << endl;
    cout << "value: " << code->value << endl;
#endif

    for (int i = 0; i < code->codes.size(); i++) {
#ifdef DEBUG
      cout << "push connection: " << code->codes[i]->order << endl;
#endif
      if (!code->codes[i]->visit) {
        code->codes[i]->before = code;
        code->codes[i]->visit = true;
        queue.push(code->codes[i]);
      }
    }
  }

  if (end_code->visit) {
    string out = "";
    Code* code = end_code;
#ifdef DEBUG
    cout << endl;
    cout << "order: " << code->order << endl;
#endif
    while (code->before != NULL) {
      out = to_string(code->order + 1) + " " + out;
#ifdef DEBUG
      cout << "before connection: " << code->before->order << endl;
      cout << "out: " << out << endl;
#endif
      code = code->before;
    }
    cout << start_code->order + 1 << " " << out;
  } else {
    cout << "-1";
  }

  for (int _n = 0; _n < n; _n++) {
    delete codes[_n];
  }
  delete[] codes;
}