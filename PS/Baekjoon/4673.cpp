#include <iostream>

using namespace std;

int ms[20000]{ 0, };

int main(void) {
    for (int m(0); m < 20000; m++) {
        int sum(m);
        for (int i(1); m >= i; i *= 10)
            sum += (m % (10 * i)) / i;
        ms[sum] = 1;
    }
    for (int i(0); i < 10000; i++)
        if (!ms[i]) cout << i << '\n';
}