// 20240822_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool canBeShot(int x, int y, int k, vector<int> point) 
{
    if (y - point[1] == k * (x-point[0]))
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
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2, 0));
    vector<vector<int>> lines(2, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    for (int i = 0; i < 2; i++)
    {
        cin >> lines[i][0] >> lines[i][1];
    }

    int k = (lines[1][1] - lines[0][1]) / (lines[1][0] - lines[0][0]);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        if (canBeShot(points[i][0], points[i][1], k, lines[0]))
        {
            result++;
        }

    }
    
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
