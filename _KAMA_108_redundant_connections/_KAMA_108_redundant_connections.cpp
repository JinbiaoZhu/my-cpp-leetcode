// _KAMA_108_redundant_connections.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

// 第一行包含一个整数 N，表示图的节点个数和边的个数。
int N;

// 初始化一个数组
vector<int> father;

// 并查集初始化
void init() 
{
	father = vector<int>(2 * N, 0);
	for (int i = 0; i <= N; i++)
	{
		father[i] = i;
	}
}

// 并查集寻找根
int findRoot(int val) 
{
	if (val == father[val])
	{
		return val;
	}

	father[val] = findRoot(father[val]);

	return father[val];

	// return val == father[val] ? val : father[val] = findRoot(father[val]);
}

// 判断 u 和 v 是否是同一根
static bool isSame(int u, int v)
{
	return findRoot(u) == findRoot(v);
}

void join(int u, int v) 
{
	if (findRoot(u)==findRoot(v))
	{
		return;
	}

	father[v] = u;

}


int main()
{
    std::cout << "Hello World!\n";

	cin >> N;
	init();

	int s, t;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> t;

		if (isSame(s, t))
		{
			cout << s << " " << t << endl;
			return 0;
		}

		join(s, t);
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
