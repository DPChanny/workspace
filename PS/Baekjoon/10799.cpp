#include<iostream>
#include<vector>

using namespace std;

int main(void) 
{
	string str;
	cin >> str;

	int layer(0), // stick layer count
		count(0); // stick count

	// true when before char was '('
	bool flag(false);

	for (size_t _i(0); _i < str.length(); _i++)
	{
		if (str[_i] == '(') 
		{
			layer++;
			flag = true;
		}
		else // (str[_i] == ')')
		{ 
			if (flag) // laser
			{
				layer--;
				count += layer;
			}
			else // end of stick
			{
				layer--;
				count++;
			}
			flag = false;
		}
	}

	cout << count;
}
