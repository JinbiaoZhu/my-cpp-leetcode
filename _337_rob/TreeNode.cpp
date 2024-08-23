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

treeNode* buildTree(vector<int>& values)
{
	vector<treeNode*> treeNodeList;

	for (vector<int>::iterator i = values.begin(); i != values.end(); i++)
	{
		if (*i != -100)
		{
			treeNode* tmp_node = new treeNode(*i);
			treeNodeList.push_back(tmp_node);
		}
		else
		{
			treeNode* tmp_node = nullptr;
			treeNodeList.push_back(tmp_node);
		}
	}

	for (int j = 0; 2 * j + 1 < treeNodeList.size(); j++)
	{
		if (treeNodeList.at(j) != nullptr)
		{
			treeNodeList.at(j)->left = treeNodeList.at(j * 2 + 1);
			if (2 * j + 2 < treeNodeList.size())
			{
				treeNodeList.at(j)->right = treeNodeList.at(j * 2 + 2);
			}
		}
	}

	return treeNodeList.at(0);
}
