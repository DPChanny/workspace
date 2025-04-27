#include<iostream>
#include<vector>

using namespace std;

typedef struct S {
	int f;
	int t;
} S;

vector<S> ss;
int c(0);

void m(int _f, int _t, int _c) {
	if (_c == 1) {
		ss.push_back({_f, _t});
		return;
	}
	m(_f, 6-_f-_t, _c - 1);
	m(_f, _t, 1);
	m(6-_f-_t, _t, _c - 1);
}

int main(void) {
	int n;
	cin >> n;
	m(1, 3, n);
	cout << ss.size() << '\n';
	for (int _ss = 0; _ss < ss.size(); _ss++)
		cout << ss[_ss].f << ' ' << ss[_ss].t << '\n';
}