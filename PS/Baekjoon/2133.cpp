#include <iostream>

using namespace std;

unsigned long long int dp[31]{1, 0, 3};

int main(void) {
    int n;
    cin >> n;
    if (n % 2) {
        cout << '0';
        return 0;
    }
    for (int _n(4); _n < n + 1; _n++) {
        dp[_n] = dp[_n - 2] * dp[2];
        for (int i(0); i * 2 < _n - 4 + 1; i++)
            dp[_n] += (dp[i * 2] * 2);
    }
    cout << dp[n];
}