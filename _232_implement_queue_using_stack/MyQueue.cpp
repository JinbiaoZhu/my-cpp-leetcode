#include "MyQueue.h"
#include<iostream>

using namespace std;

MyQueue::MyQueue()
{

}

MyQueue::~MyQueue()
{
}

void MyQueue::push(int x)
{
	sInt.push(x);
	cout << "Push a value to queue: " << x << endl;
}

int MyQueue::pop()
{
	if (sOut.empty()) 
	{
		while (!sInt.empty()) 
		{
			int tmp = sInt.top();
			sOut.push(tmp);
		}
	}
	int result = sOut.top();
	sOut.pop();
	cout << "Pop a value to queue: " << result << endl;
	return result;
}

int MyQueue::peek()
{
	int tmp = this->pop();
	this->sOut.push(tmp);
	cout << "Peek a value from queue: " << tmp << endl;
	return tmp;
}

bool MyQueue::empty()
{
	return this->sInt.empty() && this->sOut.empty();
}
