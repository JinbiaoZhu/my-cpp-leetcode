// 1049_last_stone_weight_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"lastStoneWeightII.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int N;
	cin >> N;

	vector<int> stones(N, 0);
	for (int i = 0; i < stones.size(); i++)
	{
		cin >> stones[i];
	}

	int result = lastStoneWeightII(stones);

	cout << "The result is " << result << endl;

	return 0;
}

