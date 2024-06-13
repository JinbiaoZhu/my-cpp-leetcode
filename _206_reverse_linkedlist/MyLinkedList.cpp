#include "MyLinkedList.h"
#include<iostream>

using namespace std;

MyLinkedList::MyLinkedList(int* arr, int size)
{
	this->_size = 0;
	this->_dummyHead = new LinkNode(-1);

	LinkNode* current = this->_dummyHead;

	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " ";
		LinkNode* temp = new LinkNode(arr[i]);
		current->next = temp;
		current = current->next;
	}

	cout << "The length of the linkedlist is " << this->_size << "." << endl;
}

MyLinkedList::~MyLinkedList()
{
}

MyLinkedList::LinkNode* MyLinkedList::reverseLinkedList()
{
	LinkNode* fast = this->_dummyHead->next;
	LinkNode* slow = nullptr;

	while (true)
	{
		LinkNode* temp = fast->next;
		fast->next = slow;
		slow = fast;
		if (temp == nullptr)
		{
			break;
		}
		fast = temp;
	}

	return fast;
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

void MyLinkedList::printLinkedList(MyLinkedList::LinkNode* start) 
{
	LinkNode* current = start;
	while (true)
	{
		cout << current->val << " ";
		if (current->next == nullptr)
		{
			break;
		}
		current = current->next;
	}
}



MyLinkedList::LinkNode::LinkNode(int val) :val(val), next(nullptr) {};
