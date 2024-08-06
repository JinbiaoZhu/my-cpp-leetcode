#include "preorderTraversal.h"

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
