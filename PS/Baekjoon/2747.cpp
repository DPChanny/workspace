#include<iostream>

using namespace std;

int m[45] = {};

int dp(int _n) {
    if(_n < 2) return _n;
    if(!m[_n]) m[_n] = dp(_n - 1) + dp(_n - 2);
    return m[_n];
}

int main(void) {
    int n;
    cin >> n;
    cout << dp(n);
}