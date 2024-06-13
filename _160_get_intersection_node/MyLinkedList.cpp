#include<iostream>
#include<math.h>
#include<assert.h>
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


MyLinkedList::LinkNode* getIntersectionNode(MyLinkedList::LinkNode* Head_A, MyLinkedList::LinkNode* Head_B)
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

	int delta = size_A - size_B;

	if (delta >= 0) 
	{
		delta = abs(delta);

		MyLinkedList::LinkNode* current_A = Head_A;
		MyLinkedList::LinkNode* current_B = Head_B;

		for (int i = 0; i < delta; i++) 
		{
			current_A = current_A->next;
		}

		while (true)
		{
			if (current_A->val == current_B->val) 
			{
				return current_A;
			}
			current_A = current_A->next;
			current_B = current_B->next;
			if (current_A->next == nullptr || current_B->next == nullptr) 
			{
				break;
			}
		}

	}
	if (delta < 0)
	{
		delta = abs(delta);

		MyLinkedList::LinkNode* current_A = Head_A;
		MyLinkedList::LinkNode* current_B = Head_B;

		for (int i = 0; i < delta; i++)
		{
			current_B = current_B->next;
		}

		while (true)
		{
			if (current_A->val == current_B->val)
			{
				return current_B;
			}
			current_A = current_A->next;
			current_B = current_B->next;
			if (current_A->next == nullptr || current_B->next == nullptr)
			{
				break;
			}
		}

	}

	return nullptr;
}


void printLinkedList(MyLinkedList::LinkNode* start) 
{

	MyLinkedList::LinkNode* current = start;
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