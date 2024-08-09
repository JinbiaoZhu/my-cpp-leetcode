#include "TreeNode.h"
#include<queue>

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

TreeNode* buildTree(vector<int> data)
{
	vector<TreeNode*> TreeNodeList;

	if (data.empty())
	{
		TreeNode* temp = new TreeNode(NULL);
		return temp;
	}

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

vector<int> traverse(TreeNode* root)
{
	vector<int> result;
	queue<TreeNode*> queue;

	if (root == nullptr)
	{
		return result;
	}
	else
	{
		queue.push(root);
	}

	while (!queue.empty())
	{
		int size = queue.size();

		for (int i = 0; i < size; i++)
		{
			TreeNode* temp = queue.front();
			queue.pop();
			result.push_back(temp->val);

			if (temp->left)
			{
				queue.push(temp->left);
			}

			if (temp->right)
			{
				queue.push(temp->right);
			}
		}
	}

	return result;
}