#include <iostream>
#include <vector>

using namespace std;

int n, m,
ns[8];

void r(int _n, int _m) {
    if (_m + 1 == m) {
        for (int i(0); i < m - 1; i++)
            cout << ns[i] << ' ';
        cout << _n + 1 << '\n';
        return;
    }
    ns[_m] = _n + 1;
    for (int i(0); i < n; i++)
        r(i, _m + 1);
}

int main(void) {
    cin >> n >> m;
    for (int i(0); i < n; i++)
        r(i, 0);
}