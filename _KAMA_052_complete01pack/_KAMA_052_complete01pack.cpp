// _KAMA_052_complete01pack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include"utils.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个整数，N，V，分别表示研究材料的种类和行李空间 
    // 接下来包含 N 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值
    int N, V;
    cin >> N >> V;

    vector<int> weight(N, 0);
    vector<int> values(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> values[i];
    }

    print_vector(weight);
    print_vector(values);

    // 1. 确定动态规划数组的含义: dp[i] 表示背包容量是 i 时的最大价值是 dp[i]
    // 3. 确定动态规划初始化: 全为 0 
    vector<int> dp(V + 1, 0);

    // 4. 确定动态规划的遍历顺序: 对物体正向遍历, 对重量从最小承重开始遍历
    for (int i = 0; i < N; i++)
    {
        for (int j = weight[i]; j <= V; j++)
        {
            // 2. 确定动态规划递推公式: dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
            dp[j] = max(dp[j], dp[j - weight[i]] + values[i]);
        }
    }

    // 5. 人工数值模拟
    print_vector(dp);

    cout << "The result is " << dp[V] << endl;

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
