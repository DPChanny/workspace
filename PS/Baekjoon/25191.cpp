#include<iostream>

using namespace std;

typedef long long int lli;

lli m, a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> m >> a >> b;
	cout << min(m, a / 2 + b);
}