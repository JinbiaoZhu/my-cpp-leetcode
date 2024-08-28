// _KAMA_109_redundant_connections.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;


// 声明 N 
int N;

// 先在源文件声明一个并查集
// 数据范围: 1 <= N <= 1000
vector<int> father(1001, 0);

// 并查集初始化函数
void initSet() 
{
    for (int i = 0; i <= N; i++)
    {
        father[i] = i;
    }
}

// 并查集查询和路径压缩
int find(int val) 
{
    if (val == father[val])
    {
        return val;
    }

    father[val] = find(father[val]);

    return father[val];
}

// 并查集增加节点
void join(int u, int v) 
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return;
    }

    father[v] = u;
}

// 并查集是否有共节点
bool isSame(int u, int v) 
{
    u = find(u);
    v = find(v);

    return u == v;
}

// 如果一个图是有向图, 那么就寻找可以删掉的边
//                    A
//                  /   \
//                 B -x- C
// 构建一个并查集, 如果两个节点有共节点, 那么两个节点的连接就是一个环, 那么就要删掉
void getRemovableEdge(const vector<vector<int>>& edges) 
{
    initSet();
    for (vector<int> i : edges )
    {
        if (isSame(i[0],i[1]))
        {
            cout << i[0] << " " << i[1] << endl;
        }
        else
        {
            join(i[0], i[1]);
        }
    }
}

// 判断一个有向图删除完边之后是不是有向树
bool isTreeAfterRemovingEdge(const vector<vector<int>>& edges, int node2delete) 
{
    initSet();
    for (int i = 0; i < N; i++)
    {
        if (i == node2delete)
        {
            continue;
        }
        if (isSame(edges[i][0], edges[i][1]))
        {
            return false;
        }

        join(edges[i][0], edges[i][1]);
    }
    return true;
}


int main()
{
    std::cout << "Hello World!\n";

    // 初始化 N = 节点数 = 边数
    //第一行输入一个整数 N，表示有向图中节点和边的个数。
    cin >> N;

    // 初始化每个节点的入度
    vector<int> degrees(N + 1, 0);

    // 初始化入度是 2 的节点
    vector<int> degreeIs2;

    // 把两个节点之间的边的关系存储起来
    vector<vector<int>> edges(N, vector<int>{-1, -1});
    for (int i = 0; i < N; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        degrees[edges[i][1]]++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (degrees[edges[i][1]] == 2)
        {
            degreeIs2.push_back(i);
        }
    }

    if (degreeIs2.size() > 0)
    {
        if (isTreeAfterRemovingEdge(edges, degreeIs2[0]))
        {
            cout << edges[degreeIs2[0]][0] << " " << edges[degreeIs2[0]][1] << endl;
        }
        else
        {
            cout << edges[degreeIs2[1]][0] << " " << edges[degreeIs2[1]][1] << endl;
        }
        return 0;
    }

    getRemovableEdge(edges);

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
