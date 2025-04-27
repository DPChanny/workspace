#include<iostream>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int mg(2147483647);
	for (int _g(0); _g < b.length() - a.length() + 1; _g++)
	{
		int g(0);
		for (int _a(0); _a < a.length(); _a++)
			g += (a[_a] != b[_a + _g]);
		mg = min(mg, g);
	}
	cout << mg;
}