#pragma once
#include<stack>

using namespace std;
class MyQueue
{
public:
	stack<int> sInt;
	stack<int> sOut;
	MyQueue();
	~MyQueue();
	void push(int x);
	int pop();
	int peek();
	bool empty();
};

