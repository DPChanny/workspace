#include<iostream>

using namespace std;

typedef long long int lli;

lli n, b, ms[7];

int main(void) {
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		cin >> b;
		ms[b % 7]++;
	}
	for (lli _a(0); _a < ms[1] + 1; _a++)
		for (lli _b = 0; _b < ms[2] + 1; _b++)
			for (lli _c = 0; _c < ms[3] + 1; _c++)
				for (lli _d = 0; _d < ms[4] + 1; _d++)
					for (lli _e = 0; _e < ms[5] + 1; _e++)
						for (lli _f = 0; _f < ms[6] + 1; _f++)
							if ((_a + _b * 2 + _c * 3 + _d * 4 + _e * 5 + _f * 6) % 7 == 4) {
								cout << "YES";
								exit(EXIT_SUCCESS);
							}
	cout << "NO";
}