#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

constexpr int INF = 2'000'000'000;
#define ev first
#define ew second

long long int v, e, bu, bv, bw, ds[500], cv, vcs[500];
vector<pair<int, int>> es[500];
bool vus[500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	for(int _v(0); _v < v; _v++)
		ds[_v] = INF;
	for(int _e(0); _e < e; _e++) {
		cin >> bu >> bv >> bw;
		es[bu - 1].push_back({ bv - 1, bw });
	}
	queue<int> vs;
	ds[0] = 0;
	vus[0] = true;
	vcs[0]++;
	vs.push(0);
	while(!vs.empty()) {
		cv = vs.front(); vs.pop();
		vus[cv] = false; 
		if(++vcs[cv] > e + 1) {
			cout << -1;
			return 0;
		}
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
	for(int _v(1); _v < v; _v++)
		cout << (ds[_v] == INF ? -1 : ds[_v]) << '\n';
}