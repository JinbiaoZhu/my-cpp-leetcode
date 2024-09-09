// _KAMA_127_knight_attack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>

using namespace std;

int MAP[1000 + 1][1000 + 1];
int DIR[8][2] = { -2,-1,-1,-2,
                 -2,1,-1,2,
                 2,1,1,2,
                 2,-1,1,-2 };

void bfs(int a1, int a2, int b1, int b2) 
{
    queue<int> myQueue;
    myQueue.push(a1);
    myQueue.push(a2);

    while (!myQueue.empty())
    {
        int m = myQueue.front(); myQueue.pop();
        int n = myQueue.front(); myQueue.pop();

        if (m == b1 && n == b2)
        {
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int m_ = m + DIR[i][0];
            int n_ = n + DIR[i][1];

            if (m_ < 1 || m_ > 1000 || n_ < 1 || n_ > 1000)
            {
                continue;
            }

            if (!MAP[m_][n_])
            {
                MAP[m_][n_] = MAP[m][n] + 1;
                myQueue.push(m_);
                myQueue.push(n_);
            }
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含一个整数 n，表示测试用例的数量。
    int N;
    cin >> N;

    // 接下来的 n 行，每行包含四个整数 a1, a2, b1, b2，分别表示骑士的起始位置(a1, a2) 和目标位置(b1, b2)。
    for (int i = 0; i < N; i++)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        memset(MAP, 0, sizeof(MAP));

        bfs(a1, a2, b1, b2);

        cout << MAP[b1][b2] << endl;
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
