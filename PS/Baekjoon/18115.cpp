#include <iostream>
#include <queue>

using namespace std;

int n, ns[1000000];

int main(void) {
  cin >> n;

  for (int _n(0); _n < n; _n++)
    cin >> ns[_n];

  deque<int> s;

  for (int _n(0); _n < n; _n++) {
    int behavior = ns[n - _n - 1];
    if (behavior == 1) {
      s.push_back(_n + 1);
    }
    if (behavior == 2) {
      int temp = s.back();
      s.pop_back();
      s.push_back(_n + 1);
      s.push_back(temp);
    }
    if (behavior == 3) {
      s.push_front(_n + 1);
    }
  }

  for (int _n(0); _n < n; _n++) {
    cout << s[n - _n - 1] << " ";
  }
}