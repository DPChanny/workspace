#include<iostream>
#include<cstring>

using namespace std;

int k, is[10], maxis[10], minis[10];
char ks[10];
bool ius[10];

int* max(int* _a, int* _b, const int& _n) {
	for(int __n(0); __n < _n; __n++) {
		if(_a[__n] < _b[__n]) return _b;
		if(_a[__n] > _b[__n]) return _a;
	}
	return _a;
}
int* min(int* _a, int* _b, const int& _n) {
	for(int __n(0); __n < _n; __n++) {
		if(_a[__n] < _b[__n]) return _a;
		if(_a[__n] > _b[__n]) return _b;
	}
	return _a;
}

void gmm(int _k) {
	if(_k == k + 1) {
		memcpy(maxis, max(maxis, is, k + 1), sizeof(maxis));
		memcpy(minis, min(minis, is, k + 1), sizeof(minis));
	}
	for(int _i(0); _i < 9 + 1; _i++)
		if(!ius[_i])
			if((ks[_k - 1] == '>' ? is[_k - 1] > _i : is[_k - 1] < _i)) {
				is[_k] = _i;
				ius[_i] = true;
				gmm(_k + 1);
				ius[_i] = false;
			}
}

int main(void) {
	cin >> k;
	for(int _k(0); _k < k + 1; _k++)
		minis[_k] = 9;
	for(int _k(0); _k < k; _k++)
		cin >> ks[_k];
	for(int _i(0); _i < 9 + 1; _i++) {
		is[0] = _i;
		ius[_i] = true;
		gmm(1);
		ius[_i] = false;
	}
	for(int _k(0); _k < k + 1; _k++)
		cout << maxis[_k];
	cout << '\n';
	for(int _k(0); _k < k + 1; _k++)
		cout << minis[_k];
}