#include "minDepth.h"
#include<queue>

using namespace std;

int minDepth(TreeNode* root)
{
    int depth = 0;
    queue<TreeNode*> queue;
	if (root==nullptr)
	{
		return 0;
	}
	else
	{
		queue.push(root);
	}

	while (!queue.empty())
	{
		int size = queue.size();
		depth++;

		for (int i = 0; i < size; i++)
		{
			TreeNode* temp = queue.front();
			queue.pop();
			if (temp->left == nullptr && temp->right == nullptr) 
			{
				return depth;
			}
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

	return depth;
}

int minDepth_v2(TreeNode* root)
{
	return getDepth(root);
}

// 确定递归函数输入输出
int getDepth(TreeNode* node)
{
	// 确定终止条件
	if (node == nullptr)
	{
		return 0;
	}

	int left_depth = getDepth(node->left);
	int right_depth = getDepth(node->right);

	if (node->left == nullptr && node->right != nullptr)
	{
		return 1 + right_depth;
	}
	else if (node->left != nullptr && node->right == nullptr)
	{
		return 1 + left_depth;
	}
	else
	{
		return 1 + min(left_depth, right_depth);
	}
}


