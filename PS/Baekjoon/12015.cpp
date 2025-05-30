#include <algorithm>
#include <iostream>

using namespace std;

int n, ns[1'000'001], l, bn, i;

int main(void) {
  cin >> n;
  for (int _n(0); _n < n; _n++) {
    cin >> bn;
    i = lower_bound(ns, ns + l, bn) - ns;
    ns[i] = bn;
    l = max(l, i + 1);
  }
  cout << l;
}