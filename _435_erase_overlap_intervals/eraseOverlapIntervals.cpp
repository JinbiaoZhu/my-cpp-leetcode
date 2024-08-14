#include "eraseOverlapIntervals.h"
#include<algorithm>

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    // 0.
    if (intervals.size() <= 0)
    {
        return 0;
    }
    else
    {
        // 1.
        sort(intervals.begin(), intervals.end(), compare);

        // 2.
        int count = 1;
        int current_max_value = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            // �����ǰ�����ֵ С�ڵ��� ��ǰ����������Сֵʱ��
            if (current_max_value <= intervals[i][0])
            {
                count++;
                current_max_value = intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
}


static bool compare(const vector<int>& a, const vector<int>& b) 
{
    return a[1] < b[1];
}