#include "treeNode.h"
#include<vector>
#include<iostream>

using namespace std;

treeNode::treeNode()
{
	this->nodeValue = 0;
	this->left = nullptr;
	this->right = nullptr;
}

treeNode::treeNode(int x)
{
	this->nodeValue = x;
	this->left = nullptr;
	this->right = nullptr;
}

treeNode::treeNode(int x, treeNode* left, treeNode* right)
{
	this->nodeValue = x;
	this->left = left;
	this->right = right;
}

treeNode* buildTree(const std::vector<int>& values, int index)
{
	if (index >= values.size() || values[index] == NULL)
	{
		return nullptr;
	}

	treeNode* newNode = new treeNode();
	newNode->nodeValue = values.at(index);
	cout << index << "\t" << values.at(index) << endl;
	newNode->left = buildTree(values, index + 1);
	newNode->right = buildTree(values, index + 2);
	index += 2;

	return newNode;
}
