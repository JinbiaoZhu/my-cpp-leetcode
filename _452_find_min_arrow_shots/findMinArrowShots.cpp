#include "findMinArrowShots.h"
#include<algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points)
{
	if (points.size() <= 0)
	{
		return 0;
	}
	else
	{
		int result = 1;
		sort(points.begin(), points.end(), compare);
		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] > points[i-1][1])
			{
				//////////////////////////////////////////////
				//   +++++++++++++++
				//                     +++++++++++++++++++++++
				//////////////////////////////////////////////
				result++;
			}
			else
			{
				//////////////////////////////////////////////
				//             +++++++++++++++
				//                     ++++++++++++++++++
				//////////////////////////////////////////////
				//                   ||
				//                   V
				//////////////////////////////////////////////
				//             +++++++++++++++                   
				//                     +++++++ 
				//////////////////////////////////////////////
				points[i][1] = min(points[i][1], points[i - 1][1]);
			}
		}
		return result;
	}
}

static bool compare(const vector<int>& a, const vector<int>& b) 
{
    return a[0] < b[0];
}
