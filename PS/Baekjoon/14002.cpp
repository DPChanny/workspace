#include<iostream>
#include<stack>

using namespace std;

struct N {
    int v;
    int i = -1;
};

int main(void) {
    int n;
    cin >> n;

    N* ns = new N[n];
    for (int _n(0); _n < n; _n++)
        cin >> ns[_n].v;
    int* dp = new int[n];
    for (int _n(0); _n < n; _n++) {
        int max(-1);
        for (int i(0); i < _n; i++)
            if (ns[i].v < ns[_n].v) {
                if (max == -1) max = i;
                else max = (dp[i] > dp[max] ? i : max);
            }
        if (max == -1) {
            dp[_n] = 1;
        }
        else {
            dp[_n] = dp[max] + 1;
            ns[_n].i = max;
        }
    }

    int max(0);
    for (int i(0); i < n; i++)
        max = (dp[i] > dp[max] ? i : max);
    N c(ns[max]);
    stack<int> s;
    while (c.i != -1) {
        s.push(c.v);
        c = ns[c.i];
    }
    s.push(c.v);

    cout << dp[max] << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}