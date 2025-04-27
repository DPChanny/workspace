#include<iostream>

using namespace std;

int cs[6] = {500, 100, 50, 10, 5, 1};

int main(void) {
	int n;
	cin >> n;
	n = 1000 - n;
	int s(0);
	for (int _cs = 0; _cs < 6; _cs++)
	{
		s += n / cs[_cs];
		n %= cs[_cs];
	}
	cout << s;
}