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

	for (int i=0;i<data.size(); i++) 
	{
		if (data.at(i) != -100) 
		{
			TreeNode* tmpNode = new TreeNode(data.at(i));
			TreeNodeList.push_back(tmpNode);
		}
		else
		{
			TreeNode* tmpNode;
			tmpNode = nullptr;
			TreeNodeList.push_back(tmpNode);
		}
		
	}

	for (int j = 0; 2 * j + 1 < TreeNodeList.size(); j++) 
	{
		if (TreeNodeList.at(j) != nullptr) 
		{
			TreeNodeList.at(j)->left = TreeNodeList.at(2 * j + 1);
			if (2 * j + 2 < TreeNodeList.size()) 
			{
				TreeNodeList.at(j)->right = TreeNodeList.at(2 * j + 2);
			}
		}
	}

	return TreeNodeList.at(0);
}
