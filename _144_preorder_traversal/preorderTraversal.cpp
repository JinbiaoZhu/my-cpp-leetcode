#include "preorderTraversal.h"
#include<stack>

using namespace std;

void traversalSingleNode(treeNode* treenode, vector<int>& result)
{
	if (treenode == nullptr) 
	{
		return;
	}
	result.push_back(treenode->nodeValue);
	traversalSingleNode(treenode->left, result);
	traversalSingleNode(treenode->right, result);
}

vector<int> preorderTraversal(treeNode* firstNode)
{
	vector<int> result;
	traversalSingleNode(firstNode, result);
	return result;
}

vector<int> preorderTraversalforStack(treeNode* firstNode)
{
	stack<treeNode*> treeNodeStack;
	vector<int> result;

	if (firstNode == nullptr) 
	{
		return result;
	}

	treeNodeStack.push(firstNode);
	while (!treeNodeStack.empty())
	{
		treeNode* temp = treeNodeStack.top();
		treeNodeStack.pop();
		result.push_back(temp->nodeValue);
		if (temp->right)
		{
			treeNodeStack.push(temp->right);
		}
		if (temp->left)
		{
			treeNodeStack.push(temp->left);
		}
	}
	return result;
}
