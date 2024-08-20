#include "coinChange.h"
#include"utils.h"
#include<math.h>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    int bagSize = amount;
    int coinType = coins.size();

    // 1. ȷ����̬�滮���� dp[j] ��ʾ��ֵ�� j ����µ���С��������� dp[j]
    vector<int> dp(bagSize + 1, 0);

    // 3. ȷ����̬�滮��ʼ��: dp[0] = 0, dp[j] = INT_MAX (�� VS 2022 ������ INFINITY ��ʾ)
    dp[0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = 2 << 10;
    }

    // 4. ȷ����̬�滮�ı�����ʽ: ��ȫ��������, ������������������ for ��������, �ڲ� for ѭ��������Ʒ.
    for (int i = 1; i <= bagSize; i++)
    {
        for (int j = 0; j < coinType; j++)
        {
            if (i-coins[j]>=0 && dp[i - coins[j]] != 2 << 10)
            {
                // 2. ȷ����̬�滮�ĵ��ƹ�ʽ: dp[j] = min(dp[j], dp[j-coins[i]]+1) 
                //    "ֻ��Ҫ����һ��Ǯ�� coins[i] �� dp[j - coins[i]] + 1 ���� dp[j] "
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // 5. �˹�ģ����ֵ���
    print_vector(dp);

    if (dp[bagSize] == 2 << 10)
    {
        return -1;
    }
    else 
    {
        return dp[bagSize];
    }
}
