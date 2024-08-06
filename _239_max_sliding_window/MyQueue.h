#pragma once
#include<queue>
#include<vector>

using namespace std;


class MyQueue
{
public:

	deque<int> queue;

	void pop(int value);
	void push(int value);
	int front();
};

