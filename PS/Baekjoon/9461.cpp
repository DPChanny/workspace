#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int t, n;
	cin >> t;
	for (int _t(0); _t < t; _t++)
	{
		cin >> n;

		vector<unsigned long long int> vector({ 1, 1, 1, 2, 2 });
		for (int _n(vector.size()); _n < n; _n++)
		{
			vector.push_back(vector[_n - 1] + vector[_n - 5]);
		}

		cout << vector[n - 1] << endl;
	}
}