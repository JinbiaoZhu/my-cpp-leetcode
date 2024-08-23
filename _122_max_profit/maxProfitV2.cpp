#include "maxProfitV2.h"
#include<iostream>

using namespace std;

int maxProfitV2(vector<int>& prices)
{
    int totalDays = prices.size();

    if (totalDays <= 1)
    {
        return 0;
    }

    // 1. dp[i][j] 表示第 i 天自己持有股票 j=0 和不持有股票 j=1 的身价
    vector<pair<int, int>> dp(totalDays, pair<int, int>{0,0});

    // 3. dp[0][0] = -prices[0];
    //    dp[0][1] = 0;
    dp[0].first = -prices[0];
    dp[0].second = 0;

    // 4. i = 1, 2, 3 ...
    for (int i = 1; i < totalDays; i++)
    {
        // 2. dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
        //    dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])
        dp[i].first = max(dp[i - 1].first, dp[i - 1].second - prices[i]);
        dp[i].second = max(dp[i - 1].second, dp[i - 1].first + prices[i]);
    }
    
    // 5. 人工数值模拟
    for (int i = 0; i < totalDays; i++)
    {
        cout << "(" << dp[i].first << "," << dp[i].second << ")" << endl;
    }

    return max(dp[totalDays - 1].first, dp[totalDays - 1].second);
} 
