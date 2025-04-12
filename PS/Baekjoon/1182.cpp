#include <iostream>

using namespace std;

int n, s, ns[20], c(0);

void r(int _n, long long int _s, bool _isi) {
    if (_isi && _s == s) c++;
    if (_n == n) return;
    r(_n + 1, _s + ns[_n], true);
    r(_n + 1, _s, false);
}

int main(void) {
    cin >> n >> s;
    for (int _n(0); _n < n; _n++)
        cin >> ns[_n];
    r(0, 0, false);
    cout << c;
}
