#include"MyLinkedList.h"
#include<iostream>

using namespace std;


MyLinkedList::MyLinkedList(int* arr, int size, int pos)
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
		this->_size++;
	}

	cout << endl;
	if (pos == -1) 
	{
		cout << "This linkedlist is not a loop." << endl;
	}
	else 
	{
		cout << "The size of linkedlist is " << this->_size << "." << endl;
		cout << "From " << pos << ", start looping......" << endl;

		LinkNode* start_loop = this->_dummyHead->next;
		for (int i = 0; i < pos; i++)
		{
			start_loop = start_loop->next;
		}

		current->next = start_loop;
	}
}

MyLinkedList::~MyLinkedList()
{
}

MyLinkedList::LinkNode::LinkNode(int val) 
{
	this->val = val;
	this->next = nullptr;
}

void printLinkedList(MyLinkedList::LinkNode* start) 
{
	MyLinkedList::LinkNode* current = start->next;

	for (int i=0;i<100;i++)
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

MyLinkedList::LinkNode* MyLinkedList::detectCircle() 
{
	LinkNode* fast = this->_dummyHead;
	LinkNode* slow = this->_dummyHead;
	LinkNode* index_in_start = this->_dummyHead;

	while (fast->next!=nullptr && slow->next!=nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			cout << "This Linkedlist is a loop" << endl;

			LinkNode* index_in_loop = fast;

			while (true)
			{
				if (index_in_loop == index_in_start) 
				{
					return index_in_loop;
					break;
				}
				index_in_loop = index_in_loop->next;
				index_in_start = index_in_start->next;
			}

			break;
		}
	}
	return this->_dummyHead;
}