#include<iostream>

using namespace std;

typedef long long int lli;

lli n, m, a, k;

int main(void) {
    cin >> n >> m >> a >> k;
    cout << ((a - k) / (n - 1) ? n : a - k + 1) << ' ' << (a - k) / m + ((a - k) % m ? 1 : 0) + 1;
}