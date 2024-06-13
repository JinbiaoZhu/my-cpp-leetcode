#include"MyLinkedList.h"
#include<iostream>

using namespace std;

MyLinkedList::MyLinkedList(int* arr, int size)
{
	this->_dummyHead = new LinkNode(0);
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
}

MyLinkedList::~MyLinkedList()
{
}

MyLinkedList::LinkNode::LinkNode(int val) 
{
	this->val = val;
	this->next = nullptr;
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

void MyLinkedList::removeNthFromEnd(int N) 
{

	LinkNode* fast = this->_dummyHead;
	LinkNode* slow = this->_dummyHead;

	for (int i = 0; i < N; i++) 
	{
		fast = fast->next;
	}

	while (fast->next != nullptr) 
	{
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;
}