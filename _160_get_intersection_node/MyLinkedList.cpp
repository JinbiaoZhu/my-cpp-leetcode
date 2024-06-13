#include<iostream>
#include<math.h>
#include"MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList(int* arr, int size)
{
	this->_dummyHead = new LinkNode(0);
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

void getIntersectionNode(MyLinkedList::LinkNode* Head_A, MyLinkedList::LinkNode* Head_B)
{
	MyLinkedList::LinkNode* current_A = Head_A;
	MyLinkedList::LinkNode* current_B = Head_B;

	int size_A = 0;
	int size_B = 0;

	while (current_A->next != nullptr)
	{
		current_A = current_A->next;
		size_A++;
	}

	while (current_B->next != nullptr)
	{
		current_B = current_B->next;
		size_B++;
	}

	int delta = abs(size_A - size_B);
}
