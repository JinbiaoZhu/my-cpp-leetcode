#include "change.h"
#include"utils.h"

int change(int amount, vector<int>& coins)
{
    int bagWeight = amount;
    int coinType = coins.size();

    // 1. ȷ����̬�滮������ dp[i] ��ʾ�ڱ��������� i ������»�õ�����ֵ�� dp[i]
    vector<int> dp(bagWeight + 1, 0);

    // 3. ȷ����̬�滮�ĳ�ʼ��: dp[0] = 1;
    dp[0] = 1;

    // 4. ȷ����̬�滮�ı���˳��: ������������������������������
    for (int i = 0; i < coinType; i++)
    {
        for (int j = coins[i]; j <= bagWeight; j++)
        {
            // 2. ȷ����̬�滮�ĵ��ƹ�ʽ: dp[j] += dp[j-coins[i]];
            dp[j] += dp[j - coins[i]];
        }
    }

    print_vector(dp);

    return dp[bagWeight];
}
