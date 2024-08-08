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

TreeNode* buildTree(vector<int>& data)
{
	vector<TreeNode*> TreeNodeList;

	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) != -100)
		{
			TreeNode* temp = new TreeNode(data.at(i));
			TreeNodeList.push_back(temp);
		}
		else
		{
			TreeNode* temp = nullptr;
			TreeNodeList.push_back(temp);
		}
	}

	for (int i = 0; 2 * i + 1 < TreeNodeList.size(); i++)
	{
		if (TreeNodeList.at(i))
		{
			TreeNodeList.at(i)->left = TreeNodeList.at(2 * i + 1);
			if (2 * i + 2 < TreeNodeList.size())
			{
				TreeNodeList.at(i)->right = TreeNodeList.at(2 * i + 2);
			}
		}
	}

	return TreeNodeList.at(0);
}
