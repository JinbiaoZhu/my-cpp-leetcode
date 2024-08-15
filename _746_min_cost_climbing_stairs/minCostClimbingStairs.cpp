#include "minCostClimbingStairs.h"
#include<vector>
#include<iostream>

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    // 1. ȷ����̬�滮��������±�: dp[i] ��ʾ������ i ��̨������Ҫ�ġ����١�����
    vector<int> dp;
    
    // 3. ȷ�����Ƴ�ʼ��: dp[0]=0, dp[1]=0
    // ��Ŀ:"�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�"
    dp.push_back(0);
    dp.push_back(0);


    // 4. ȷ������˳��: ��ǰ���������ұ���
    for (int i = 2; i < cost.size()+1; i++)
    {
        // 2. ȷ�����ƹ�ʽ: dp[i]= min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        // ע���ǡ����١�����
        dp.push_back(
            min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        );
    }

    // 5. ȷ���Լ�����˳��: dp[0]=0, dp[1]=0, dp[2]=1, dp[3]=2, dp[4]=2, ...
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size() - 1];
}
