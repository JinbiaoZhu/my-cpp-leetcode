#include"topKFrequent.h"
#include"myComparation.h"
#include<unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) 
{
	unordered_map<int, int> myMap;
	for (int i = 0; i < nums.size(); i++) 
	{
		myMap[nums.at(i)]++;
	}

	for (unordered_map<int, int>::iterator i = myMap.begin();
		i != myMap.end(); i++) 
	{
		cout << "key: " << i->first << "\t" 
			<< "value: " << i->second << endl;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, myComparation> pri_que;

	for (unordered_map<int, int>::iterator i=myMap.begin(); i != myMap.end(); i++) 
	{
		pri_que.push(*i);
		if (pri_que.size() > k) 
		{
			pri_que.pop();
		}
	}

	vector<int> result(k);
	for (int i = k - 1; i >= 0; i--) 
	{
		result.at(i) = pri_que.top().first;
		pri_que.pop();
	}

	return result;

}