// 1035_max_uncrossed_lines.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
{
    int rowLength = nums1.size(), colLength = nums2.size();

    // 1. 确定动态规划数组:
    //    dp[i][j] 表示下标是 1~i-1 的 nums1 子序列和
    //    下标是 1~j-1 的 nums2 子序列的最长公共子序列
    // 3. 确定动态规划初始化:
    //    dp[x][0] = 0 || dp[0][y] = 0
    vector<vector<int>> dp(rowLength + 1, vector<int>(colLength + 1, 0));  

    // 4. 确定动态规划遍历顺序:
    //    两个循环嵌套, 分别遍历两个列表
    //    从前向后, 从左向右循环
    for (int row = 1; row <= rowLength; row++)
    {
        for (int col = 1; col <= colLength; col++)
        {
            // 2. 确定动态规划递推公式:
            //    如果 nums[i-1] == nums[j-1] 则 dp[i][j] = dp[i-1][j-1] + 1
            //    如果 nums[i-1] != nums[j-1] 则 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            if (nums1[row-1]==nums2[col-1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else
            {
                dp[row][col] = max(dp[row][col - 1], dp[row - 1][col]);
            }
            // 5. 人工数值模拟
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    
    return dp[rowLength][colLength];
}

int main()
{
    std::cout << "Hello World!\n";

    int nums1Length, nums2Length;
    cin >> nums1Length >> nums2Length;

    vector<int> nums1(nums1Length, 0);
    vector<int> nums2(nums2Length, 0);

    for (int i = 0; i < nums1Length; i++)
    {
        cin >> nums1[i];
    }

    for (int j = 0; j < nums2Length; j++)
    {
        cin >> nums2[j];
    }

    int result = maxUncrossedLines(nums1, nums2);

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
