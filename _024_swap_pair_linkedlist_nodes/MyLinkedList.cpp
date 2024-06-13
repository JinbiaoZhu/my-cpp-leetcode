#include"MyLinkedList.h"
#include<iostream>

using namespace std;

MyLinkedList::MyLinkedList(int* arr,int size)
{
	this->_dummyHead = new LinkNode(0);
	LinkNode* current = this->_dummyHead;

	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " ";
		LinkNode* tmp = new LinkNode(arr[i]);
		current->next = tmp;
		current = tmp;
	}
	cout << endl;
	cout << "The size of the linked list is " << this->_size << "." << endl;
}

MyLinkedList::~MyLinkedList()
{
}

MyLinkedList::LinkNode::LinkNode(int val) 
{
	this->val = val;
	this->next = nullptr;
}

void MyLinkedList::swapPairLinkedlistNodes() 
{
	LinkNode* current = this->_dummyHead;

	while (current->next != nullptr && current->next->next != nullptr) 
	{
		LinkNode* Node_A = current->next;
		LinkNode* Node_B = current->next->next->next;
		
		current->next = current->next->next;
		current->next->next = Node_A;
		current->next->next->next = Node_B;

		current = current->next->next;
	}

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