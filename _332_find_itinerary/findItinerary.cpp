#include "findItinerary.h"

using namespace std;

vector<string> findItinerary(vector<vector<string>>& tickets)
{
	// 'unordered_map' 的 value 是按照字母表顺序排列的
    unordered_map<string, map<string, int>> flightTable;
	vector<string> result;

	for (const vector<string>& vec : tickets)
	{
		flightTable[vec[0]][vec[1]]++;
	}

	result.push_back("JFK");

	backtrack(flightTable, result, tickets.size());

	return result;
}

bool backtrack(unordered_map<string, map<string, int>>& flightTable, vector<string>& result, int ticketNum)
{
	if (result.size() == ticketNum + 1)
	{
		return true;
	}

	string name = result[result.size() - 1];
	for (pair<const string, int>& target : flightTable[name])
	{
		if (target.second > 0)
		{
			result.push_back(target.first);
			target.second--;
			if (backtrack(flightTable, result, ticketNum)) 
			{
				return true;
			}
			result.pop_back();
			target.second++;
		}
	}
	return false;
}