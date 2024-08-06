#include "TreeNode.h"

TreeNode::TreeNode()
{
	this->val = 0;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::TreeNode(int x)
{
	this->val = x;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right)
{
	this->val = x;
	this->left = left;
	this->right = right;
}

TreeNode* buildTree(vector<int> data, int index)
{
	if (index >= data.size() || data[index] == NULL) 
	{
		return nullptr;
	}

	TreeNode* newNode = new TreeNode();
	newNode->val = data[index];
	newNode->left = buildTree(data, index + 1);
	newNode->right = buildTree(data, index + 2);
	index += 2;

	return newNode;

}
