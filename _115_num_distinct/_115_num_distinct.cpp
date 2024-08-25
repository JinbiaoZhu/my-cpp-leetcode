// _115_num_distinct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) 
{
    int sLength = s.size(), tLength = t.size();

    // 1. 确定动态规划数组 dp[i][j]
    //    表示以 i-1 结尾的字符串 s 中出现 j-1 结尾的字符串 t 的次数
    vector<vector<int>> dp(sLength + 1, vector<int>(tLength + 1, 0));

    // 3. 确定动态规划初始化
    //    dp[0][y] = 0; dp[x][0] = 1; dp[0][0] = 1;
    for (int row = 0; row < sLength; row++)
    {
        dp[row][0] = 1;
    }

    // 4. 确定遍历顺序
    //    两个循环嵌套, 从前向后从左向右
    for (int row = 1; row <= sLength; row++)
    {
        for (int col = 1; col <= tLength; col++)
        {
            // 2. 确定动态规划递推表达式
            //    如果 s[i-1] == t[j-1] 则 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            //    如果 s[i-1] != t[j-1] 则 dp[i][j] = dp[i-1][j];
            if (s[row-1] == t[col-1])
            {
                dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
            }
            else
            {
                dp[row][col] = dp[row - 1][col];
            }
            // 5. 人工数值模拟
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }
    
    // 6. 返回动态规划数组末尾
    return dp[sLength][tLength];
}

int main()
{
    std::cout << "Hello World!\n";

    string s, t;
    cin >> s;
    cin >> t;

    int result = numDistinct(s, t);

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
