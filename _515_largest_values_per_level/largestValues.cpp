#include "largestValues.h"
#include<queue>
#include<math.h>

vector<int> largestValues(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> queue;

	if (root==nullptr)
	{
		return result;
	}
	else
	{
		queue.push(root);
	}

	while (!queue.empty())
	{
		int max = -1 * INFINITY;
		int size = queue.size();

		for (int i = 0; i < size; i++)
		{
			TreeNode* node = queue.front();
			queue.pop();
			if (node->val>=max)
			{
				max = node->val;
			}
			if (node->left) 
			{
				queue.push(node->left);
			}
			if (node->right)
			{
				queue.push(node->right);
			}
		}

		result.push_back(max);
	}

	return result;
}
