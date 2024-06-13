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

	int get(int index);
	void addAtHead(int val);
	void addAtTail(int val);
	void addAtIndex(int val, int index);
	void deletaAtIndex(int index);
	void printLinkedList();

private:

	int _size;
	LinkNode* _dummyHead;

};

