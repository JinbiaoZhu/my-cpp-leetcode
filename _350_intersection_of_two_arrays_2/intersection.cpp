#include"intersection.h"
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> intersection(vector<int> A, vector<int> B) 
{
	vector<int> result;
	unordered_map<int, int> count_map;

	for (int i : A) 
	{
		count_map[i]++;
	}

	for (int j : B) 
	{
		if (count_map[j] > 0) 
		{
			result.push_back(j);
			count_map[j]--;
		}
	}

	return result;
}

void printVector(vector<int> result) 
{
	for (const int& i : result) 
	{
		cout << i << " ";
	}
	cout << endl;
}