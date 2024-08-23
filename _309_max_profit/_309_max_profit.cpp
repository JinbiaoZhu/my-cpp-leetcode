// _309_max_profit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    int totalDays = prices.size();

    if (totalDays == 0)
    {
        return 0;
    }

    int totalStatus = 4;

    // 1. 确定动态规划数组 dp[i][j] 表示第 i 天自己的状态是 j 
    //    包括: (1)持有股票, (2)不持有股票, (3)今日卖出, (4)股票冻结 
    vector<vector<int>> dp(totalDays, vector<int>(totalStatus, 0));

    // 3. 确定动态规划初始化:
    //    dp[0][0] = -1 * prices[0];
    //    dp[0][1] = 0;
    //    dp[0][2] = 0;
    //    dp[0][3] = 0;
    dp[0][0] = -1 * prices[0];
    
    // 4. 确定动态规划的遍历: 从前向后从左向右
    for (int i = 1; i < totalDays; i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            // 2. 确定动态规划递推公式:
            //    dp[i][0]: 原先就持有股票 + 保持不变 || 原本不持有股票条件 + 今日购买 || 原本冻结状态 + 今日购买
            //    dp[i][1]: 原先就不持有股票 + 保持不变 || 原本冻结状态 + 保持不变
            //    dp[i][2]: 原先持有股票 + 今天卖出
            //    dp[i][3]: 今日卖出股票
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
    }
    
    // 5. 人工模拟数值结果
    for (vector<int> i: dp)
    {
        for (int j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int current_max = 0;
    for (int i : dp[totalDays-1])
    {
        if (i > current_max)
        {
            current_max = i;
        }
    }

    return current_max;
}



int main()
{
    std::cout << "Hello World!\n";

    int priceLength;
    cin >> priceLength;

    vector<int> prices(priceLength, 0);
    for (int i = 0; i < priceLength; i++)
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
