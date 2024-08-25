// _516_longest_palindrome_subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s) 
{
    int length = s.size();

    vector<vector<int>> dp(length, vector<int>(length, 0));

    for (int i = 0; i < length; i++)
    {
        dp[i][i] = 1;
    }

    for (int row = length - 1; row >= 0; row--)
    {
        for (int col = row + 1; col < length; col++)
        {
            if (s[row] == s[col])
            {
                dp[row][col] = dp[row + 1][col - 1] + 2;
            }
            else
            {
                dp[row][col] = max(dp[row + 1][col], dp[row][col - 1]);
            }
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    return dp[0][length - 1];
}

int main()
{
    std::cout << "Hello World!\n";

    string s;
    cin >> s;

    int result = longestPalindromeSubseq(s);

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
