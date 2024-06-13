#pragma once

class MyLinkedList
{
public:
	MyLinkedList(int *arr,int size, int pos);
	~MyLinkedList();

	struct LinkNode
	{
		int val;
		LinkNode* next;
		LinkNode(int val);
	};

	LinkNode* detectCircle();

	LinkNode* _dummyHead;
	int _size;

private:

};


void printLinkedList(MyLinkedList::LinkNode* start);

