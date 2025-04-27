#include <iostream>
#include <algorithm>

using namespace std;

int ns[500000];

int main(void) {
    int n;
    cin >> n;
    for (int _n(0); _n < n; _n++)
        cin >> ns[_n];
    sort(ns, ns + n);
    long long s(0);
    for (int _n(0); _n < n; _n++)
        s += abs(ns[_n] - (_n + 1));
    cout << s;
}
