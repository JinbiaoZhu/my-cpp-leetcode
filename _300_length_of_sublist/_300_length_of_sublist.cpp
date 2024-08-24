// _300_length_of_sublist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) 
{
    int totalLength = nums.size();

    // 1. dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
    // 3. dp[i] 初始化全 1
    vector<int> dp(totalLength, 1);

    // 2. dp[i] = max(dp[i], dp[j]+1) if (nums[i] > nums[j]) 其中 j = 0,...,i-1
    // 4. 先遍历 i 再遍历 j 都是从前向后从左向右
    for (int i = 1; i < totalLength; i++)
    {
        for (int j = 0; j <= i ; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 5. 人工数值模拟
    for (int i: dp)
    {
        cout << i << " ";
    }
    cout << endl;

    int result = 0;
    for (int i : dp) 
    {
        if (result < i)
        {
            result = i;
        }
    }

    return result;
}

int main()
{
    std::cout << "Hello World!\n";

    int numsLength;
    cin >> numsLength;

    vector<int> nums(numsLength, 0);
    for (int i = 0; i < numsLength; i++)
    {
        cin >> nums[i];
    }

    int result = lengthOfLIS(nums);
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
