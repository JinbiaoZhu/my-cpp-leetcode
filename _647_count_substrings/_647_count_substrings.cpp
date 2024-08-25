// _647_count_substrings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubstrings(string s) 
{
    int length = s.size();
    int result = 0;

    // 1. dp[row][col] 字符串 [row, col] 区间是否是回文串
    //    所以这里蕴含 row <= col
    // 3. dp 初始化全 false
    vector<vector<bool>> dp(length, vector<bool>(length, false));

    // 4. 遍历: row 从大到小遍历; col 从小到大遍历
    for (int row = length-1; row >= 0; row--)
    {
        for (int col = row; col < length; col++)
        {
            // 2. 如果 s[row] != s[col] 那么 dp[row][col] = false;
            //    如果 s[row] == s[col] 那么分三种情况讨论:
            //  i)  当 row - col == 0 时, dp[row][col] = true;
            // ii)  当 row - col == 1 时, dp[row][col] = true;
            //iii)  当 row - col >= 2 时, 如果 dp[row + 1][col - 1] == true 则 dp[row][col] = true;
            // iv)  当 row - col >= 2 时, 如果 dp[row + 1][col - 1] == false 则 dp[row][col] = false;
            if (s[row] != s[col])
            {
                dp[row][col] = false;
            }
            else
            {
                if (col - row == 0)
                {
                    dp[row][col] = true;
                    result++;
                }
                else if (col - row == 1)
                {
                    dp[row][col] = true;
                    result++;
                }
                else
                {
                    if (dp[row + 1][col - 1] == true)
                    {
                        dp[row][col] = true;
                        result++;
                    }
                }
            }
            // 5. 人工模拟数值结果
            if (dp[row][col])
            {
                cout << "true" << " ";
            }
            else
            {
                cout << "false" << " ";
            }
        }
        cout << endl;
    }

    // 6. 返回数组中结果是 true 的个数
    return result;
}

int main()
{
    std::cout << "Hello World!\n";

    string s;
    cin >> s;

    int result = countSubstrings(s);

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
