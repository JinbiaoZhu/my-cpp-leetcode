// _KAMA_046_01bagweight.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int n, bagweight;
    cin >> n >> bagweight;

    vector<int> weight(n, 0);  // 物体重量表格
    vector<int> value(n, 0);   // 物体价值表格

    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> value[i];
    }

    // 1. 确定动态规划数组: dp[i][j] 表示放入任意数量的 weight[0] 到 weight[i] 物体到承重为 j 的背包能产生的最大价值。
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));

    // 3. 确定动态规划是如何初始化的: 背包重量 j 只有大于等于物体重量才能在 dp 数组中产生价值;
    //    这个是横向初始化, 也就是先确定 dp 数组的第一行:
    //    如果第 0 个物体的重量小于背包重量, 就初始化第 0 个物体重量的价值;
    //    如果第 0 个物体的重量大于背包重量, dp 表格就初始化为 0 , 上面已经初始化好了。
    for (int i = weight[0]; i <= bagweight; i++)
    {
        dp[0][i] = value[0];
    }

    // 4. 确定动态规划的遍历顺序: 这道题先遍历物体和先遍历背包是都可以的;
    for (int i = 1; i < weight.size(); i++)
    {
        for (int j = 0; j <= bagweight; j++)
        {
            if (j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else  // j >- weight[i]
            {
                // 2. 确定动态规划递推公式: dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
                // 5. 举例子推导动态规划数组: 省略
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    for (int row = 0; row < dp.size(); row++)
    {
        for (int col = 0; col < dp[0].size(); col++)
        {
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }
    
    cout << dp[n - 1][bagweight] << endl;

    return 0;
}
