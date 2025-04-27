#include<iostream>
#include<algorithm>

using namespace std;

constexpr int CC = 2;
constexpr int NM = 128;
constexpr int W = 0;
constexpr int B = 1;
constexpr int SC = 4;

enum class S { w, b, m };

int n, cs[CC];
bool ns[NM][NM];

S gwbc(int _s, int _y, int _x) {
	if(_s == 1) return (S)ns[_y][_x];
	S ss[SC]{
		gwbc(_s / 2, _y, _x),
		gwbc(_s / 2, _y, _x + _s / 2) ,
		gwbc(_s / 2, _y + _s / 2, _x) ,
		gwbc(_s / 2, _y + _s / 2, _x + _s / 2) };
	if(equal(ss + 1, ss + SC, ss)) return ss[0];
	for(int _s(0); _s < SC; _s++)
		if(ss[_s] != S::m) cs[(int)ss[_s]]++;
	return S::m;
}

int main(void) {
	cin >> n;
	for(int _y(0); _y < n; _y++)
		for(int _x(0); _x < n; _x++)
			cin >> ns[_y][_x];
	S l = gwbc(n, 0, 0);
	if(l != S::m) cs[(int)l]++;
	cout << cs[W] << '\n' << cs[B];
}
