#include<iostream>
#include<algorithm>

using namespace std;

int a, b, as[500000], bs[500000], ambs[500000], amb;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for(int _a(0); _a < a; _a++)
		cin >> as[_a];
	for(int _b(0); _b < b; _b++)
		cin >> bs[_b];
	sort(as, as + a);
	sort(bs, bs + b);
	for(int _a(0); _a < a; _a++)
		if(!binary_search(bs, bs + b, as[_a])) ambs[amb++] = as[_a];
	cout << amb << '\n';
	for(int _amb(0); _amb < amb; _amb++)
		cout << ambs[_amb] << ' ';
}