#include "MyLinkedList.h"

MyLinkedList::MyLinkedList()
{
	this->_dummyHead = new LinkNode(-1);
	this->_size = 0;
}

MyLinkedList::~MyLinkedList()
{
}

void MyLinkedList::addAtTail(int val)
{
	LinkNode* current = this->_dummyHead->next;

	while (current->next!=nullptr)
	{
		current = current->next;
	}

	LinkNode* newNode = new LinkNode(val);
	current->next = newNode;
	this->_size++;
}

int* MyLinkedList::changeLinkedListToArray()
{

}

MyLinkedList::LinkNode::LinkNode(int val)
{
	this->val = val;
	this->next = nullptr;
}

