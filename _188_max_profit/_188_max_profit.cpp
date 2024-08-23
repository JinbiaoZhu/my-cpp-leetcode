// _188_max_profit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) 
{
    int totalDays = prices.size();

    // 1. 确定动态规划数组: dp[i][j] 表示第 i 天的股票处于第 j 个状态时自己的身价
    vector<vector<int>> dp(totalDays, vector<int>(2 * k + 1, 0));

    // 3. 确定初始化:
    //    dp[0][偶数] = 0;
    //    dp[0][奇数] = -1 * prices[奇数];
    for (int i = 0; i < 2 * k + 1; i++)
    {
        if (i % 2 == 0)
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = -1 * prices[0];
        }
    }
    
    // 4. 确定遍历顺序: 从前向后从左向右
    for (int row = 1; row < totalDays; row++)
    {
        for (int col = 0; col < 2 * k - 1; col+=2)
        {
            // 2. 确定动态规划递推公式:
            //    dp[i][0] = dp[i-1][0];  // 表示第 i-1 天的股票处于无操作状态时第 i 天的状态
            //    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])  // 表示第 i 天的股票处于买入时的身价
            //    dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])  // 表示第 i 天的股票处于卖出时的身价
            //    dp[i][奇] = max(dp[i-1][奇], dp[i-1][偶] - prices[i])  // 表示第 i 天的股票处于买入时的身价
            //    dp[i][偶] = max(dp[i-1][偶], dp[i-1][奇] + prices[i])  // 表示第 i 天的股票处于卖出时的身价
            dp[row][col + 1] = max(dp[row - 1][col + 1], dp[row - 1][col] - prices[row]);
            dp[row][col + 2] = max(dp[row - 1][col + 2], dp[row - 1][col + 1] + prices[row]);
        }

    }

    // 5. 人工数值模拟
    for (int i = 0; i < totalDays; i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[totalDays - 1][2 * k];
}

int main()
{
    std::cout << "Hello World!\n";

    int k, pricesLength;
    cin >> k >> pricesLength;

    vector<int> prices(pricesLength, 0);
    for (int i = 0; i < pricesLength; i++)
    {
        cin >> prices[i];
    }

    int result = maxProfit(k, prices);

    cout << result << endl;

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
