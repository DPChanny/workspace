#include<iostream>
#include<queue>

using namespace std;

int n, k, ks[100], c;
bool ksu[100];
queue<int> kso[100];
vector<int> ns;

int main(void) {
	cin >> n >> k;
	for(int _k(0); _k < k; _k++) {
		cin >> ks[_k];
		ks[_k]--;
		kso[ks[_k]].push(_k);
	}
	for(int _k(0); _k < k; _k++) {
		kso[ks[_k]].pop();
		if(ksu[ks[_k]]) continue;
		ksu[ks[_k]] = true;
		if(ns.size() < n) ns.push_back(ks[_k]);
		else {
			int i(0);
			for(int _n(0); _n < n; _n++) {
				if(kso[ns[_n]].empty()) {
					i = _n;
					break;
				} else if(kso[ns[_n]].front() > kso[ns[i]].front()) i = _n;
			}
			c++;
			ksu[ns[i]] = false;
			ns[i] = ks[_k];
		}
	}
	cout << c;
}