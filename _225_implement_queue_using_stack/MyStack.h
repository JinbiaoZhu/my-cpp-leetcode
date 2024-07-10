#pragma once
#include<queue>

using namespace std;


class MyStack
{
public:
	MyStack();
	~MyStack();
	void push(int x);
	int pop();
	int top();
	bool empty();
	queue<int> queue_main;
	queue<int> queue_vice;
};

