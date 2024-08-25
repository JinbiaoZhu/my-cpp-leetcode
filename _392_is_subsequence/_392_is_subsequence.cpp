// _392_is_subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSubsequence(string s, string t) 
{
    // s 是模式串 t 是源串 s 来匹配 t
    // 所以 s 的长度要比 t 短一些 
    // 题目: 0 <= s.length <= 100, 0 <= t.length <= 10^4
    int rowLength = s.size(), colLength = t.size();

    // 1. 创建动态规划数组 dp[i][j] 表示从 1 到 i-1 索引的 s 字符串
    //    和 1 到 j-1 索引的 t 字符串的最大字串长度
    // 3, 确定动态规划初始化:
    //    dp[0][y] = 0;  // s 是模式串, s 是空串表示最大匹配长度是 0
    //    dp[x][0] = 0;  // t 是源串, t 是空串表示最大匹配长度是 0
    vector<vector<int>> dp(rowLength + 1, vector<int>(colLength + 1, 0));

    // 4. 确定遍历顺序:
    //    两个都是从小到大从前向后排列
    for (int row = 1; row <= rowLength; row++)
    {
        for (int col = 1; col <= colLength; col++)
        {
            // 2. 确定动态规划递推公式:
            //    如果 s[i-1] == t[j-1] 则 dp[i][j] = dp[i-1][j-1] + 1
            //    如果 s[i-1] != t[j-1] 则 
            if (s[row-1] == t[col-1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else
            {
                dp[row][col] = dp[row][col - 1];
            }
            // 5. 人工模拟数值结果
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    // 6. 结果选 dp 里面的两个最大下标
    if (dp[rowLength][colLength] == rowLength)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::cout << "Hello World!\n";

    string s, t;

    cin >> s;
    cin >> t;

    bool result = isSubsequence(s, t);

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

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
