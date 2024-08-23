// _121_max_profit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

void print_vector(vector<pair<int,int>>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "(" << nums[i].first << "," << nums[i].second << ")" << " ";
    }
    cout << endl;
}

int maxProfit(vector<int>& prices) 
{
    int totalDays = prices.size();

    if (totalDays <= 1)
    {
        return -1 * prices[totalDays - 1];
    }

    // 1. 确定动态规划数组: dp[i][j] 表示第 i 天持有股票 j=0 和没有持有股票 j=1 的总价值
    vector<pair<int, int>> dp(totalDays, pair<int, int>{0, 0});

    // 3. 确定动态规划初始化:
    // 1) dp[0][0] 表示第 i 天持有股票 j=0 此时价值是 -prices[0]
    // 2) dp[0][1] 表示第 i 天不持股票 j=1 此时价值是 0
    dp[0].first = -1 * prices[0];
    dp[0].second = 0;

    // 4，确定动态规划递推方向: 从前向后, 从左向右
    for (int i = 1; i < totalDays; i++)
    {
        // 2. 确定动态规划递推公式:
        // 1) 当前持有股票时: 可能已经存在, 也可能是今天买入: dp[i][0] = max(dp[i-1][0], -prices[i])
        // 2) 当前没有持有时: 可能已经不存在, 也可能今天卖出: dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])'
        dp[i].first = max(dp[i - 1].first, -1 * prices[i]);
        dp[i].second = max(dp[i - 1].second, dp[i - 1].first + prices[i]);
    }

    // 5. 人工数值模拟
    print_vector(dp);

    cout << max(dp[totalDays-1].first, dp[totalDays-1].second) << endl;
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
