#include "is_happy_number.h"
#include<unordered_set>
#include<iostream>

using namespace std;

int getSum(int n)
{
	vector<int> tmp;
	int new_n=0;
	cout << "The data is " << n << " " << endl;
	while (n) 
	{
		tmp.push_back(n % 10);
		n /= 10;
	}

	for (const int& i : tmp) 
	{
		cout << i << " ";
		new_n += (i * i);
	}

	cout << "The new_n is " << new_n << "." << endl;

	return new_n;
}

bool isHappy(int n)
{
	unordered_set<int> record;
	
	while (true)
	{
		int new_n = getSum(n);
		if (new_n == 1)
		{
			return true;
		}
		else
		{
			if (record.count(new_n))
			{
				return false;
			}
			else
			{
				record.insert(new_n);
			}
		}

		n = new_n;
	}
}


