// _KAMA_046_01bagweight_v2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int n_objects, bag_weight;
    cin >> n_objects >> bag_weight;

    vector<int> weight(n_objects, 0);
    vector<int> value(n_objects, 0);

    for (int i = 0; i < n_objects; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n_objects; i++)
    {
        cin >> value[i];
    }

    // 1. 确定动态规划数组: dp[i] 表示在 i 重量下的最大价值是多少
    // 3. 确定动态规划的初始化: 初始 dp[i] 全部为 0 即可, 表示最开始都没有价值
    vector<int> dp(bag_weight + 1, 0);

    // 4. 确定数组遍历条件: 对物体正向顺序, 对背包承重反向顺序
    for (int i = 0; i < n_objects; ++i)
    {
        for (int j = bag_weight; j >= weight[i]; --j)
        {
            // 2. 确定动态规划的递推公式: dp[j] = max( dp[j] , dp[j-weight[i]]+value[i] )
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // 5. 人工模拟出 dp[i] 的数值
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }

    cout << dp[bag_weight] << endl;

    return 0;
}
