#include<iostream>
#include<algorithm>

using namespace std;

int a, b, as[200'000], bs[200'000], ap, bp, us[400'000], up;

int main(void) {
	cin >> a >> b;
	for(int _a(0); _a < a; _a++)
		cin >> as[_a];
	for(int _b(0); _b < b; _b++)
		cin >> bs[_b];
	sort(as, as + a);
	sort(bs, bs + b);
	if(bs[bp] > as[ap]) us[up++] = as[ap++];
	else us[up++] = bs[bp++];
	while(ap != a && bp != b) {
		if(bs[bp] > as[ap]) {
			if(us[up - 1] == as[ap]) {
				up--;
				ap++;
			} else us[up++] = as[ap++];
		} else {
			if(us[up - 1] == bs[bp]) {
				up--;
				bp++;
			} else us[up++] = bs[bp++];
		}
	}
	while(ap != a) {
		if(us[up - 1] == as[ap]) {
			up--;
			ap++;
		} else us[up++] = as[ap++];
	}
	while(bp != b) {
		if(us[up - 1] == bs[bp]) {
			up--;
			bp++;
		} else us[up++] = bs[bp++];
	}
	cout << up;
}