// _KAMA_117_software_building.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 第一行输入两个正整数 N, M。表示 N 个文件之间拥有 M 条依赖关系。
    // 后续 M 行，每行两个正整数 S 和 T，表示 T 文件依赖于 S 文件。
    int N, M;
    cin >> N >> M;

    unordered_map<int, vector<int>> umap(N);
    vector<int> inDegree(N);
    vector<int> result;

    for (int i = 0; i < M; i++)
    {
        int s, t;
        cin >> s >> t;

        inDegree[t]++;
        umap[s].push_back(t);
    }

    queue<int> myQueue;
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
        {
            myQueue.push(i);
        }
    }

    while (myQueue.size())
    {
        int node = myQueue.front();
        myQueue.pop();

        result.push_back(node);
        vector<int> filepath = umap[node];
        if (!filepath.empty())
        {
            for (int i = 0; i < filepath.size(); i++)
            {
                inDegree[filepath[i]]--;
                if (inDegree[filepath[i]] == 0)
                {
                    myQueue.push(filepath[i]);
                }
            }
        }
    }

    if (result.size() == N)
    {
        for (int i = 0; i < result.size() - 1; i++)
        {
            cout << result[i] << " ";
        }
    }
    cout << result[result.size() - 1] << endl;

    cout << endl;


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
