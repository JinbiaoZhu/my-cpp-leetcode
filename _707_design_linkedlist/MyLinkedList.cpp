#include"MyLinkedList.h"
#include<iostream>

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
		this->_size++;
	}

	cout << endl;
	cout << "The length of the linkedlist is " << this->_size << "." << endl;

}

MyLinkedList::~MyLinkedList()
{
}

int MyLinkedList::get(int index)
{
	if (index<0 || index>this->_size) 
	{
		return -1;
	}

	LinkNode* current = this->_dummyHead;

	for (int i = 0; i < index; i++) 
	{
		current = current->next;
	}


	return current->next->val;
}

void MyLinkedList::addAtHead(int val)
{
	LinkNode* temp = this->_dummyHead->next;
	LinkNode* newNode = new LinkNode(val);
	this->_dummyHead->next = newNode;
	newNode->next = temp;
}

void MyLinkedList::addAtTail(int val)
{
	LinkNode* current = this->_dummyHead;
	while (true)
	{
		if (current->next == nullptr)
		{
			break;
		}
		current = current->next;
	}
	LinkNode* newNode = new LinkNode(val);
	current->next = newNode;
}

void MyLinkedList::addAtIndex(int val, int index)
{
	LinkNode* current = this->_dummyHead;
	for (int i = 0; i < index; i++) 
	{
		current = current->next;
	}
	LinkNode* temp = current->next;
	LinkNode* newNode = new LinkNode(val);
	current->next = newNode;
	newNode->next = temp;
}

void MyLinkedList::deletaAtIndex(int index)
{
	LinkNode* current = this->_dummyHead;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	current->next = current->next->next;
}

void MyLinkedList::printLinkedList()
{
	LinkNode* current = this->_dummyHead->next;
	while (true)
	{
		cout << current->val << " ";
		if (current->next==nullptr)
		{
			break;
		}
		current = current->next;
	}
	cout << endl;
}

MyLinkedList::LinkNode::LinkNode(int val)
{
	this->val = val;
	this->next = nullptr;
}
