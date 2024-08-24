// _714_max_profit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) 
{
    int totalDays = prices.size();

    // 1. 确定动态规划数组:
    //    dp[i][0] 表示第 i 天持有股票的身价
    //    dp[i][1] 表示第 i 天不持有股票的身价
    vector<vector<int>> dp(totalDays, vector<int>(2, 0));

    // 3. 确定动态规划初始化:
    //    dp[0][0] = -prices[i];  // 第 0 天持有股票则自己身价是 -1 * prices[i]
    //    dp[0][1] = 0;           // 第 0 天不持有股票自己身价就是 0
    dp[0][0] = -1 * prices[0];

    // 4. 确定动态规划遍历顺序:
    //    从小到大, 从前到后
    for (int i = 1; i < totalDays; i++)
    {
        // 2. 确定动态规划递推公式:
        //    dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
        //    dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }

    // 5. 人工数值模拟
    for (vector<int> i: dp)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << "(" << i[0] << "," << i[1] << ")" << endl;
        }
        cout << endl;
    }

    return max(dp[totalDays - 1][0], dp[totalDays - 1][1]);
}

int main()
{
    std::cout << "Hello World!\n";

    int pricesLength, fee;
    cin >> pricesLength >> fee;

    vector<int> prices(pricesLength, 0);
    for (int i = 0; i < pricesLength; i++)
    {
        cin >> prices[i];
    }

    int result = maxProfit(prices, fee);

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
