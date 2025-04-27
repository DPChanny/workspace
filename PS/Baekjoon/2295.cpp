#include<iostream>
#include<algorithm>

using namespace std;

int n, ns[1000], ans[1000000], anc;

int main(void){
	cin >> n;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	sort(ns, ns + n);
	for(int x(0); x < n; x++)
		for(int y(x); y < n; y++)
			ans[anc++] = ns[x] + ns[y];
	sort(ans, ans + anc);
	anc = unique(ans, ans + anc) - ans;
	for(int _k(n - 1); _k + 1 > 0; _k--)
		for(int _z(0); _z < _k + 1; _z++)
			if(binary_search(ans, ans + anc, ns[_k] - ns[_z])) {
				cout << ns[_k];
				return 0;
			}
}