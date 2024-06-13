#include"MyLinkedList.h"
#include <iostream>

using namespace std;

MyLinkedList::MyLinkedList(int* arr, int size)
{
	this->_dummyHead = new LinkNode(-1);
	this->_size = 0;

	LinkNode* current = this->_dummyHead;

	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " ";
		LinkNode* tmp = new LinkNode(arr[i]);
		current->next = tmp;
		current = current->next;
	}
	cout << endl;

	cout << "The length of the linkedlist is " << this->_size << "." << endl;

}

MyLinkedList::~MyLinkedList()
{
}

void MyLinkedList::printLinkedList()
{
	LinkNode* current = this->_dummyHead->next;

	while (true)
	{
		cout << current->val << " ";
		if (current->next == nullptr)
		{
			break;
		}
		current = current->next;
	}

	cout << endl;
}

void MyLinkedList::removeNthElements(int N)
{
	LinkNode* current = this->_dummyHead;

	for (int i = 0; i < N; i++)
	{
		current = current->next;
	}

	current->next = current->next->next;
}

MyLinkedList::LinkNode::LinkNode(int val)
{
	this->val = val;
	this->next = nullptr;
}
