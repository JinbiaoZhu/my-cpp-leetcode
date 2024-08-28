// _KAMA_110_string_solitaire.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    // 先处理输入
    // 第一行包含一个整数 N，表示字典 strList 中的字符串数量。
    // 第二行包含两个字符串，用空格隔开，分别代表 beginStr 和 endStr。
    // 后续 N 行，每行一个字符串，代表 strList 中的字符串。
    int N;
    cin >> N;

    string beginStr, endStr;
    cin >> beginStr >> endStr;

    vector<string> strList(N, "");
    for (int i = 0; i < N; i++)
    {
        cin >> strList[i];
    }

    // 设置键值对数据结构用来存储是否访问过
    unordered_map<string, int> isVisitedMap;

    // 使用广度优先搜索
    queue<string> myQueue;
    myQueue.push(beginStr);
    isVisitedMap.insert(pair<string, int>{beginStr, 1});

    while (!myQueue.empty())
    {
        string word = myQueue.front();
        myQueue.pop();
        
        int path = isVisitedMap[word];

        for (int i = 0; i < word.size(); i++)  // 遍历单词中的每一个字符
        {
            string newWord = word;  // 拷贝原来的字符

            for (int j = 0; j < 26; j++)
            {
                newWord[i] = 'a' + j;

                if (newWord == endStr)  // 替换之后能直接找到 endStr , 那么就是路径数值 + 1
                {
                    cout << path + 1 << endl;
                    return 0;
                }

                // 如果在存储字符串的列表中找到了, 且这个字符串没有被访问过
                if (find(strList.begin(), strList.end(), newWord) != strList.end()
                    && isVisitedMap.find(newWord) == isVisitedMap.end()
                    )
                {
                    // 先标记访问, 然后把这个字符串增加到队列中
                    isVisitedMap.insert(pair<string, int>{newWord, path + 1});
                    myQueue.push(newWord);
                }
            }
        }
    }

    cout << 0 << endl;

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
