#pragma once
class MyLinkedList
{
public:

	MyLinkedList();
	~MyLinkedList();

	struct LinkNode
	{
		int val;
		LinkNode* next;
		LinkNode(int val);
	};

	void addAtTail(int val);
	int* changeLinkedListToArray();

private:

	int _size;
	LinkNode* _dummyHead;
};

