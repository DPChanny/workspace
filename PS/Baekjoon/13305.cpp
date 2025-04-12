#include<iostream>

typedef long long int lld;

using namespace std;

lld n, nds[100'000], cn(1'000'000'000), r, t;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (lld _n(0); _n < n - 1; _n++)
        cin >> nds[_n];
    for (lld _n(0); _n < n - 1; _n++) {
        cin >> t;
        cn = min(cn, t);
        r += nds[_n] * cn;
    }
    cout << r;
}