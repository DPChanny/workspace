#include<iostream>

using namespace std;

uint32_t a, b, ta, tb, t;

int main(void) {
	cin >> a >> b;

	ta = a;
	tb = b;

	while(tb) {
		t = tb;
		tb = ta % tb;
		ta = t;
	}

	cout << ta << '\n' << a * b / ta;
}