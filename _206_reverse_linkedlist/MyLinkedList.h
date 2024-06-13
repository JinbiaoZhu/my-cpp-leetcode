#pragma once
class MyLinkedList
{
public:

	MyLinkedList(int * arr,int size);
	~MyLinkedList();

	struct LinkNode
	{
		int val;
		LinkNode* next;
		LinkNode(int val);
	};

	LinkNode* reverseLinkedList();
	void printLinkedList();
	void printLinkedList(LinkNode* start);

private:

	int _size;
	LinkNode* _dummyHead;

};

