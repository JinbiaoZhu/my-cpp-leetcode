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

	void printLinkedList();

private:

	int _size;
	LinkNode* _dummyHead;

};

void getIntersectionNode(MyLinkedList::LinkNode Head_A, MyLinkedList::LinkNode Head_B);

