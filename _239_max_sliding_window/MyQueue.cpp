#include "MyQueue.h"

void MyQueue::pop(int value)
{
	if (!this->queue.empty() && value == queue.front())
	{
		queue.pop_front();
	}
}

void MyQueue::push(int value)
{
	while (!queue.empty() && value > queue.back())
	{
		queue.pop_back();
	}
	queue.push_back(value);
}

int MyQueue::front()
{
	return queue.front();
}
