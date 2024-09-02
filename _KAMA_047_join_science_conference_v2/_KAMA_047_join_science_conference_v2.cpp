// _KAMA_047_join_science_conference_v2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include <vector>
#include <list>
#include <queue>

# define infinity 9999

using namespace std;

// 创建一个可以包含权值的链表节点
struct linkNode
{
    int to;
    int val;
    linkNode(int to_, int val_) : to(to_), val(val_) {};  // 结构体的构造函数
};

// 创建小顶堆的排序逻辑
class myComparation
{
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) 
    {
        // 因为小顶堆存储的都是数对, 
        // 第一个位置存储的是下一个位置的链接, 
        // 第二个位置存储的是权值
        return lhs.second > rhs.second;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    // 第一行包含两个正整数，第一个正整数 N 表示一共有 N 个公共汽车站，第二个正整数 M 表示有 M 条公路。 
    int N, M;
    cin >> N >> M;

    // 接下来为 M 行，每行包括三个整数，S、E 和 V，代表了从 S 车站可以单向直达 E 车站，并且需要花费 V 单位的时间。
    int S, E, V;
    vector<list<linkNode>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> S >> E >> V;
        adj[S].push_back(linkNode(E, V));
    }

    // 开始进行 dijkstra 算法
    int start = 1;
    int end = N;

    // 1. 初始化当前节点距离源节点的最短路径列表
    vector<int> minDist(N + 1, infinity);
    //    初始化当前节点是否遍历过的记录
    vector<bool> isVisited(N + 1, false);

    // 2. 采用堆优化
    //    第一个位置: The type of the stored elements.
    //    第二个位置: The type of the underlying container to use to store the elements. 
    //                The container must satisfy the requirements of SequenceContainer, 
    //                    and its iterators must satisfy the requirements of LegacyRandomAccessIterator. 
    //                    Additionally, it must provide the following functions with the usual semantics.
    //    第三个位置: A Compare type providing a strict weak ordering. 
    //                Note that the Compare parameter is defined such that it returns true 
    //                    if its first argument comes before its second argument in a weak ordering.
    //                    But because the priority queue outputs largest elements first, 
    //                    the elements that "come before" are actually output last.
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparation> prioriQueue;

    // 3. 初始化小顶堆
    prioriQueue.push(pair<int, int>(start, 0));
    minDist[start] = 0;

    while (!prioriQueue.empty())
    {
        pair<int, int> currentNode = prioriQueue.top();
        prioriQueue.pop();

        if (isVisited[currentNode.first] == true)
        {
            continue;
        }

        isVisited[currentNode.first] = true;

        for (linkNode node : adj[currentNode.first])
        {
            if (isVisited[node.to] == false && node.val + minDist[currentNode.first] < minDist[node.to])
            {
                minDist[node.to] = node.val + minDist[currentNode.first];
                prioriQueue.push(pair<int, int>(node.to, minDist[node.to]));
            }
        }
    }

    if (minDist[end] == infinity)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minDist[end] << endl;
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
