#include "merge.h"
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> result;

	if (intervals.size()==0)
	{
		return result;
	}
	else
	{
		sort(intervals.begin(), intervals.end(), compare);

		result.push_back(intervals[0]);

		for (int i = 1; i < intervals.size(); i++)
		{
			if (result.back()[1]>=intervals[i][0])
			{
				//  重叠情况如下：
				//  ---------------------------|
				//                            -|--------------------------------
				result.back()[1] = max(result.back()[1], intervals[i][1]);
			}
			else
			{
				//  非重叠情况如下：
				//  ---------------------------
				//                               ---------------------------------
				result.push_back(intervals[i]);
			}
		}
		return result;
	}
}

static bool compare(const vector<int>& a, const vector<int>& b) 
{
	return a[0] < b[0];
}
