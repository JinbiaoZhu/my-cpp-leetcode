#include "climbStairs.h"
#include<vector>
#include<iostream>

using namespace std;

int climbStairs(int n)
{
    // 1. ȷ����̬�滮������±�
    vector<int> dp;

    // 3. ȷ����̬�滮�ĳ�ʼ����: dp[1] = 1; dp[2] = 2;
    if (n<=2)
    {
        return n;
    }
    else
    {
        dp.push_back(1);
        dp.push_back(2);
    }

    // 4. ȷ������˳��: ��С����, ��ǰ���
    for (int i = 3 - 1; i < n; i++)
    {
        // 2. ȷ����̬�滮�ĵ��ƹ�ʽ: dp[i] = dp[i-1] + dp[i-2];
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    
    // 5. ȷ���˹�����; dp[1]=1; dp[2]=2; dp[3]=3; dp[4]=5; dp[5]=8 (�� index Ϊ 1 ��ʼ)
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[dp.size() - 1];
}
