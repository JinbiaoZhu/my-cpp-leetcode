#include "connect.h"
#include<queue>

using namespace std;

TreeNode* levelTraverse(TreeNode* root)
{
	queue<TreeNode*> queue;

	if (root == nullptr)
	{
		return nullptr;
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
			TreeNode* tmp = queue.front();
			queue.pop();
			if (i == size-1)
			{
				tmp->next = nullptr;
			}
			else
			{
				tmp->next = queue.front();
			}
			if (tmp->left)
			{
				queue.push(tmp->left);
			}
			if (tmp->rigth) 
			{
				queue.push(tmp->rigth);
			}
		}
	}

	return root;
}

vector<int> traverseTree(TreeNode* root)
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
			TreeNode* tmp = queue.front();
			queue.pop();
			result.push_back(tmp->val);
			if (tmp->next==nullptr)
			{
				result.push_back(-100);
			}
			if (tmp->left)
			{
				queue.push(tmp->left);
			}
			if (tmp->rigth)
			{
				queue.push(tmp->rigth);
			}
		}
	}

	return result;
}
