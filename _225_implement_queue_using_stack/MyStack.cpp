#include "MyStack.h"
#include<queue>
#include<iostream>

using namespace std;

MyStack::MyStack() 
{
}

MyStack::~MyStack()
{
}

void MyStack::push(int x)
{
	this->queue_main.push(x);
	cout << "Push the value x " << x << " to the stack." << endl;
}

int MyStack::pop()
{
	int count = this->queue_main.size() - 1;
	
	for (int step = 0; step < count; step++) 
	{
		this->queue_vice.push(this->queue_main.front());
		this->queue_main.pop();
	}
	
	int result = this->queue_main.front();
	this->queue_main.pop();

	this->queue_main = this->queue_vice;
	while (!this->queue_vice.empty())
	{
		this->queue_vice.pop();
	}

	cout << "Pop the value x: " << result << endl;
	return result;
}

int MyStack::top()
{
	cout << "The top value is: " << this->queue_main.back() << endl;
	return this->queue_main.back();
}

bool MyStack::empty()
{
	return this->queue_main.empty();
}
