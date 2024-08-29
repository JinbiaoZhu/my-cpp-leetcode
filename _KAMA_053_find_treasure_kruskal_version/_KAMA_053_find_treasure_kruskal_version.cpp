// _KAMA_053_find_treasure_kruskal_version.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include"DisjointSet.h"
#include"Edge.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int V, E;
    int v1, v2, val;

    int N = 10001;
    int result_value = 0;
    vector<int> fatherSet(N, -1);
    vector<Edge> myEdges(N);
    vector<Edge> result_edges;
    
    cin >> V >> E;
    for (int i = 0; i < N; i++)
    {
        cin >> v1 >> v2 >> val;
        myEdges.push_back({ v1,v2,val });
    }

    sort(myEdges.begin(),
        myEdges.end(),
        [](Edge& a, Edge& b)
        {
            return a.weight < b.weight;
        }
    );

    init(fatherSet);

    for (int i = 0; i < N; i++)
    {
        int x = find(fatherSet, myEdges[i].left);
        int y = find(fatherSet, myEdges[i].right);

        if (x != y)
        {
            result_edges.push_back(myEdges[i]);
            result_value += myEdges[i].weight;
            join(fatherSet, x, y);
        }

    }

    for (Edge edge : myEdges )
    {
        cout << edge.left << " -> " << edge.right << endl;
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
