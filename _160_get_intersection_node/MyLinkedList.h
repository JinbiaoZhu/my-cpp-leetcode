#pragma once


class MyLinkedList
{
public:
	MyLinkedList(int *arr,int size);
	~MyLinkedList();

	struct LinkNode
	{
		int val;
		LinkNode* next;
		LinkNode(int val);
	};

	int _size;
	LinkNode* _dummyHead;

private:

};

MyLinkedList::LinkNode* getIntersectionNode(MyLinkedList::LinkNode* Head_A, MyLinkedList::LinkNode* Head_B);

void printLinkedList(MyLinkedList::LinkNode* start);

