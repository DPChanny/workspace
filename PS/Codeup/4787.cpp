#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class BOX {
public:
	int start;
	int end;
	int amount;

	bool operator<(BOX _a) {
		return this->start > _a.start;
	}

	BOX(int _start, int _end, int _amount) {
		start = _start;
		end = _end;
		amount = _amount;
	}
};

int main(void) {
	int n, c, m;
	cin >> n >> c >> m;

	vector<vector<BOX>> boxes(n);

	for (int _m = 0; _m < m; _m++)
	{
		int start, end, amount;
		cin >> start >> end >> amount;
		start--;
		end--;
		
		boxes[end].push_back(BOX(start, end, amount));
	}

	for (int _n = 0; _n < n; _n++)
	{
		sort(boxes[_n].begin(), boxes[_n].end());
	}

	int* amounts = new int[n] {0, };
	int count = 0;
	for (int _n = 0; _n < n; _n++)
	{
		for (int i = 0; i < boxes[_n].size(); i++)
		{
			int max = 0;
			for (int j = boxes[_n][i].start; j < boxes[_n][i].end; j++)
			{
				if (amounts[j] > max) {
					max = amounts[j];
				}
			}
			int amount;
			if (c - max > boxes[_n][i].amount) {
				amount = boxes[_n][i].amount;
			}
			else {
				amount = c - max;
			}
			count += amount; 
			for (int j = boxes[_n][i].start; j < boxes[_n][i].end; j++)
			{
				amounts[j] += amount;
			}
		}
	}

	cout << count;

	delete[] amounts;
}