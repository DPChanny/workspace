#include<stdio.h>
#include<stdlib.h>

int dp[20][20][20] = {0, }; //dp[a][b][c]

int w(int _a, int _b, int _c) {
    if (_a <= 0 || _b <= 0 || _c <= 0)
        return 1;

    if (_a > 20 || _b > 20 || _c > 20)
        return 1048576;

    if (!dp[_a - 1][_b - 1][_c - 1]) {
        if (_a < _b && _b < _c)
            dp[_a - 1][_b - 1][_c - 1] = 
                w(_a, _b, _c - 1) + 
                w(_a, _b - 1, _c - 1) - 
                w(_a, _b - 1, _c);

        else
            dp[_a - 1][_b - 1][_c - 1] = 
                w(_a - 1, _b, _c) + 
                w(_a - 1, _b - 1, _c) + 
                w(_a - 1, _b, _c - 1) - 
                w(_a - 1, _b - 1, _c - 1);
    }

    return dp[_a - 1][_b - 1][_c - 1];
}

int main(void) {
    int a, b, c;

    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}