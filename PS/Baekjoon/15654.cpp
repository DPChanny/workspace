#include <iostream>
#include <algorithm>

using namespace std;

int n, m,
vn[8],
sns[8],
ns[8];

void r(int _n, int _m) {
    if (vn[_n]) return;
    if (_m + 1 == m) {
        for (int i(0); i < m - 1; i++)
            cout << ns[sns[i]] << ' ';
        cout << ns[_n] << '\n';
        return;
    }
    vn[_n] = 1;
    sns[_m] = _n;
    for (int i(0); i < n; i++)
        r(i, _m + 1);
    vn[_n] = 0;
}

int main(void) {
    cin >> n >> m;
    for (int i(0); i < n; i++)
        cin >> ns[i];
    sort(ns, ns + n);
    for (int i(0); i < n; i++)
        r(i, 0);
}