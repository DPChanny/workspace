#include<iostream>
#include<algorithm>

using namespace std;

class Line {
public:
    int start;
    int end;

    bool operator<(const Line& _line) const {
        return this->start < _line.start;
    }
};

int main(void) {
    int n;
    cin >> n;

    Line* ns = new Line[n];
    for (int _n(0); _n < n; _n++)
        cin >> ns[_n].start >> ns[_n].end;

    sort(ns, ns + n);

    int* dp = new int[n];
    for (int _n(0); _n < n; _n++) {
        int max(0);
        for (int i(0); i < _n; i++)
            if (ns[i].end < ns[_n].end)
                if (dp[i] > max)
                    max = dp[i];
        dp[_n] = max + 1;
    }

    int max(0);
    for (int i(0); i < n; i++)
        if (dp[i] > max)
            max = dp[i];

    cout << n - max;

    delete[] ns;
    delete[] dp;
}