#include <iostream>

using namespace std;

int n, m,
nv[8],
ns[8];

void r(int _n, int _m) {
    if (nv[_n]) return;
    if (_m + 1 == m) {
        for (int i(0); i < m - 1; i++)
            cout << ns[i] << ' ';
        cout << _n + 1 << '\n';
        return;
    }
    nv[_n] = 1;
    ns[_m] = _n + 1;
    for (int i(ns[_m]); i < n; i++)
        r(i, _m + 1);
    nv[_n] = 0;
}

int main(void) {
    cin >> n >> m;
    for (int i(0); i < n; i++)
        r(i, 0);
}