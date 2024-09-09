// _127_KAMA_knight_attack_v2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>

using namespace std;

int a1, a2, b1, b2;
int DIR[8][2] = { -2,-1,-1,-2,-2,1,-1,2,2,1,1,2,2,-1,1,-2 };
int MAP[1001][1001];

struct KNIGHT
{
    int x, y;

    // F = G + H
    // G = 从起点到该节点路径消耗
    // H = 该节点到终点的预估消耗
    int g, h, f;

    bool operator < (const KNIGHT& k) const {
        return k.f < f;
    };
};

priority_queue<KNIGHT> myKnightQueue;

int HEURISTIC(const KNIGHT& k) 
{
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}

void A_star(const KNIGHT& k) 
{
    KNIGHT current, next;

    myKnightQueue.push(k);

    while (!myKnightQueue.empty())
    {
        current = myKnightQueue.top();
        myKnightQueue.pop();

        if (current.x == b1 && current.y == b2)
        {
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            next.x = current.x + DIR[i][0];
            next.y = current.y + DIR[i][1];

            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000)
            {
                continue;
            }

            if (!MAP[next.x][next.y])
            {
                MAP[next.x][next.y] = MAP[current.x][current.y] + 1;

                next.g = current.g + 5;
                next.h = HEURISTIC(next);
                next.f = next.g + next.h;

                myKnightQueue.push(next);
            }
        }
    }
}


int main()
{
    std::cout << "Hello World!\n";

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a1 >> a2 >> b1 >> b2;

        memset(MAP, 0, sizeof(MAP));

        KNIGHT start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = HEURISTIC(start);
        start.f = start.g + start.h;

        A_star(start);

        while (!myKnightQueue.empty())
        {
            myKnightQueue.pop();
        }

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


