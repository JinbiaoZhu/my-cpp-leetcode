// _123_max_profit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    int totalDays = prices.size();

    // 1. 确定动态规划数组: dp[i][j] 表示第 i 天的第 j 状态下自己的身价
    vector<vector<int>> dp(totalDays, vector<int>(5, 0));

    // 3. 确定初始化
    // dp[0][0] = 0; 
    // dp[0][1] = -prices[0]; dp[0][2] = 0; 
    // dp[0][3] = -prices[0]; dp[0][4] = 0;
    dp[0][0] = 0;
    dp[0][1] = -1 * prices[0];
    dp[0][2] = 0;
    dp[0][3] = -1 * prices[0];
    dp[0][4] = 0;

    // 4. 确定动态规划递推顺序: 从前向后从左向右
    for (int i = 1; i < totalDays; i++)
    {
        // 2. 确定动态规划递推公式: 
        // dp[i][0] 表示没有买卖操作状态, 那么身价是不变的;
        // dp[i][1] 表示第 i 天持有这支股票的身价: 要么是 dp[i-1][1] 要么是 dp[i-1][0] - prices[i]
        // dp[i][2] 表示第 i 天没持有这股票的身价: 要么是 dp[i-1][2] 要么是 dp[i-1][1] + prices[i]
        // dp[i][3] 表示第 i 天持有这支股票的身价: 要么是 dp[i-1][3] 要么是 dp[i-1][4] - prices[i]
        // dp[i][4] 表示第 i 天没持有这股票的身价: 要么是 dp[i-1][4] 要么是 dp[i-1][3] + prices[i]

        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
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

    int current_max = dp[totalDays - 1][0];
    for (int i = 0; i < dp[totalDays-1].size(); i++)
    {
        if (dp[totalDays-1][i] > current_max)
        {
            current_max = dp[totalDays - 1][i];
        }
    }

    return current_max;
}

int main()
{
    std::cout << "Hello World!\n";

    int pricesLength;
    cin >> pricesLength;

    vector<int> prices(pricesLength, 0);
    for (int i = 0; i < pricesLength; i++)
    {
        cin >> prices[i];
    }

    int result = maxProfit(prices);

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
