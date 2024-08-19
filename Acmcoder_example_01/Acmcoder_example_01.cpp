#include<iostream>
#include<vector>
#include<limits>
#include<numeric>

using namespace std;

class Solution 
{
public:
	int isEvenNum(int n) 
	{
		if (n % 2 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

int main() 
{
	int result;

	int n;
	cin >> n;

	Solution* s = new Solution();
	result = s->isEvenNum(n);
	cout << result << endl;

	int n_0, n_1, n_2;
	cin >> n_0 >> n_1 >> n_2;
	cout << n_0 << n_1 << n_2 << endl;

	return 0;
}