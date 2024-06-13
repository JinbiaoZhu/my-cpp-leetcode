#pragma once

class MyLinkedList
{
public:
	MyLinkedList(int* arr, int size);
	~MyLinkedList();

	struct LinkNode
	{
		int val;
		LinkNode* next;
		LinkNode(int val);
	};

	void swapPairLinkedlistNodes();
	void printLinkedList();

private:

	LinkNode* _dummyHead;
	int _size;

};

