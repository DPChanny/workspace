#include<iostream>
#include<vector>
#include<queue>

using namespace std;

constexpr int INF = 1'000'000;
#define ev first
#define ew second

int v, e, s, bu, bv, bw, ds[20'000 + 1], cv;
vector<pair<int, int>> es[20'000 + 1];
bool vus[20'000 + 1];

struct compare {
	bool operator()(const int& _a, const int& _b) {
		return ds[_a] > ds[_b];
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e >> s;
	for(int _v(1); _v < v + 1; _v++)
		ds[_v] = INF;
	for(int _e(0); _e < e; _e++) {
		cin >> bu >> bv >> bw;
		es[bu].push_back({ bv, bw });
	}
	priority_queue<int, vector<int>, compare> vs;
	ds[s] = 0;
	vus[s] = true;
	vs.push(s);
	while(!vs.empty()) {
		cv = vs.top(); vs.pop();
		vus[cv] = false;
		for(int _e(0); _e < es[cv].size(); _e++) {
			if(ds[es[cv][_e].ev] > ds[cv] + es[cv][_e].ew) {
				ds[es[cv][_e].ev] = ds[cv] + es[cv][_e].ew;
				if(!vus[es[cv][_e].ev]) {
					vus[es[cv][_e].ev] = true;
					vs.push(es[cv][_e].ev);
				}
			}
		}
	}
	for(int _v(1); _v < v + 1; _v++) {
		if(ds[_v] == INF) cout << "INF" << '\n';
		else cout << ds[_v] << '\n';
	}
}