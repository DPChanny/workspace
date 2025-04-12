#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool** graph; //관계표
bool* visit; //visit[i] i번째 인원 탐색 여부
int n; //인원수

void searchGroup(int _from, vector<int>* _group) {
	if (visit[_from]) {
		return;
	}

	_group->push_back(_from);
	visit[_from] = true;

	for (int _n = 0; _n < n; _n++)
	{
		if (graph[_from][_n]) {
			searchGroup(_n, _group);
		}
	}
}

int searchTime(int _from, int _main) {
	queue<int> queue;
	queue.push(_from);
	int time = 0;
	while (!queue.empty()) {
		int s = queue.size();
		for (int _s = 0; _s < s; _s++)
		{
			int from = queue.front();
			queue.pop();

			if (from == _main) {
				return time;
			}

			for (int _n = 0; _n < n; _n++)
			{
				if (graph[from][_n]) {
					queue.push(_n);
				}
			}
		}
		time++;
	}
}

int searchMaxTime(vector<int>* _group, int _main) {
	int max = 0;
	for (int i = 0; i < _group->size(); i++)
	{
		int time = searchTime(_group->at(i), _main);
		if(time > max){
			max = time;
		}
	}
	return max;
}

int main(void) {
	int m; //관계수
	cin >> n >> m;

	//graph[from][to]
	graph = new bool* [n];
	for (int _n = 0; _n < n; _n++)
	{
		graph[_n] = new bool[n] {false, };
	}

	for (int _m = 0; _m < m; _m++)
	{
		int buf1, buf2;
		cin >> buf1 >> buf2;
		buf1--;
		buf2--;
		graph[buf1][buf2] = true;
		graph[buf2][buf1] = true;
	}

	visit = new bool[n] {false, };

	vector<vector<int>*> groups; //위원회 인원
	vector<int> mains; //위원회 대표

	for (int _n = 0; _n < n; _n++)
	{
		if (!visit[_n]) {
			groups.push_back(new vector<int>);
			searchGroup(_n, groups.back());
		}
	}

	for (int i = 0; i < groups.size(); i++)
	{
		int id = 0;
		int min = searchMaxTime(groups[i], groups[i]->at(id));
		for (int j = id + 1; j < groups[i]->size(); j++)
		{
			int time = searchMaxTime(groups[i], groups[i]->at(j));
			if (time < min) {
				min = time;
				id = j;
			}
		}
		mains.push_back(groups[i]->at(id));
	}

	cout << mains.size() << endl;
	while(!mains.empty()){
		int id = 0;
		int min = mains[id];
		for (int i = id + 1; i < mains.size(); i++)
		{
			if (min > mains[i]) {
				min = mains[i];
				id = i;
			}
		}
		cout << min + 1 << endl;
		mains.erase(mains.begin() + id);
	}

	for (int i = 0; i < groups.size(); i++)
	{
		delete groups[i];
	}
	for (int _n = 0; _n < n; _n++)
	{
		delete[] graph[_n];
	}
	delete[] graph;
	delete[] visit;
}