#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string a, b;
	getline(cin >> ws, a);
	getline(cin >> ws, b);
	if (a.length() < b.length()) {
		cout << 0;
		return 0;
	}
	int c(0);
	for (int _g(0); _g < a.length() - b.length() + 1; _g++)
	{
		bool f(true);
		for (int _b(0); _b < b.length(); _b++)
		{
			if (a[_g + _b] != b[_b]) {
				f = false;
				break;
			}
		}
		if (f) {
			c++;
			_g += b.length() - 1;
		}
	}
	cout << c;
}