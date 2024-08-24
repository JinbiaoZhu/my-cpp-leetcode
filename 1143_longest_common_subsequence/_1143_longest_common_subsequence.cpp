// _1143_longest_common_subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) 
{
    int text1Length = text1.size();
    int text2Length = text2.size();
    int current_max = 0;

    // 1. dp[i][j] 表示 text1[0:i-1] 和 text[0:j-1] 的最长公共子串的长度
    vector<vector<int>> dp(text1Length + 1, vector<int>(text2Length + 1, 0));

    for (int row = 0; row <= text1Length; row++)
    {
        for (int col = 0; col <= text2Length; col++)
        {
            // 3. dp[x][0] = 0; dp[0][y] = 0;
            if (row == 0 || col == 0)
            {
                dp[row][col] == 0;
            }
            else
            {
                // 2. 如果 text1[i] == text2[j] 
                //    那么 dp[i][j] = dp[i-1][j-1] + 1;
                //    如果 text1[i] != text2[j] 
                //    那么 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[row - 1] == text2[col - 1])
                {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                }
                else
                {
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
                }
            }

            if (dp[row][col] > current_max)
            {
                current_max = dp[row][col];
            }

            // 5. 人工模拟数值结果
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }
    
    return current_max;
}

int main()
{
    std::cout << "Hello World!\n";

    string text1, text2;
    cin >> text1;
    cin >> text2;

    int result = longestCommonSubsequence(text1, text2);

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
