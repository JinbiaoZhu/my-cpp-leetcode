#include "TreeNode.h"
#include<queue>

using namespace std;

TreeNode::TreeNode()
{
	this->val = 0;
	this->left = nullptr;
	this->rigth = nullptr;
}

TreeNode::TreeNode(int x)
{
	this->val = x;
	this->left = nullptr;
	this->rigth = nullptr;
}

TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right)
{
	this->val = x;
	this->left = left;
	this->rigth = right;
}

TreeNode* buildTree(vector<int>& data)
{
	vector<TreeNode*> TreeNodeList;

	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) != -100)
		{
			TreeNode* tmp = new TreeNode(data[i]);
			TreeNodeList.push_back(tmp);
		}
		else
		{
			TreeNode* tmp = nullptr;
			TreeNodeList.push_back(tmp);
		}
	}

	for (int i = 0; 2 * i + 1 < TreeNodeList.size(); i++)
	{
		if (TreeNodeList.at(i))
		{
			TreeNodeList.at(i)->left = TreeNodeList.at(2 * i + 1);
			if (2 * i + 2 < TreeNodeList.size())
			{
				TreeNodeList.at(i)->rigth = TreeNodeList.at(2 * i + 2);
			}
		}
	}

	return TreeNodeList.at(0);
}
