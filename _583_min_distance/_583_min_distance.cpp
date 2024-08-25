// _583_min_distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<vector>

using namespace std;

int minDistance(string word1, string word2) 
{
    int word1Length = word1.size(), word2Length = word2.size();

    // 1. dp[i][j] 表示以 i-1 结尾的 word1 和以 j-1 结尾的 word2 
    // 在可以删除字符的条件下达到相等需要的最字符数
    vector<vector<int>> dp(word1Length + 1, vector<int>(word2Length + 1, 0));

    // 3. dp[0][y] = y 表示 word2 删掉自己的长度字符才能和 word1 空串一样
    //    dp[x][0] = x 表示 word1 删掉自己的长度字符才能和 word2 空串一样
    for (int row = 0; row <= word1Length; row++)
    {
        dp[row][0] = row;
    }
    for (int col = 0; col <= word2Length; col++)
    {
        dp[0][col] = col;
    }

    // 4. dp 遍历顺序, 双嵌套, 从左向右从上向下
    for (int row = 1; row <= word1Length; row++)
    {
        for (int col = 1; col <= word2Length; col++)
        {
            // 2. 如果 word1[i-1] == word2[j-1] 那么 dp[i][j] = dp[i-1][j-1]
            //    如果 word1[i-1] != word2[j-1] 那么
            //        i) 保留 word1 删掉 word2 , dp[i][j-1] + 1
            //       ii) 保留 word2 删掉 word1 , dp[i-1][j] + 1
            //      iii) 删掉 word1 删掉 word2 , dp[i-1][j-1] + 2
            //       iv) 最后选择这三种情况的最小值
            if (word1[row-1] == word2[col-1])
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                dp[row][col] = min(dp[row - 1][col] + 1,dp[row][col - 1] + 1);
            }
            // 5. 人工数值模拟
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    // 6. 返回数值是 dp 数组的右下角
    return dp[word1Length][word2Length];
}

int main()
{
    std::cout << "Hello World!\n";

    string word1, word2;
    cin >> word1;
    cin >> word2;

    int result = minDistance(word1, word2);

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
