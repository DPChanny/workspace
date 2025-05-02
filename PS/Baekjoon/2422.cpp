#include <iostream>
#include <vector>

using namespace std;

bool exceptions[200][200];

int main(void) {
  int n, m;
  cin >> n >> m;
  for (int _n(0); _n < m; _n++) {
    int b1, b2;
    cin >> b1 >> b2;
    exceptions[b1 - 1][b2 - 1] = exceptions[b2 - 1][b1 - 1] = true;
  }

  int r(0);

  for (int _n1(0); _n1 < n; _n1++)
    for (int _n2(_n1 + 1); _n2 < n; _n2++)
      for (int _n3(_n2 + 1); _n3 < n; _n3++)
        if (!exceptions[_n1][_n2] && !exceptions[_n2][_n3] &&
            !exceptions[_n1][_n3])
          r++;

  cout << r;
}