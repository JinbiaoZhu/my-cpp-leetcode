#include "levelOrder.h"
#include<queue>
#include<iostream>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root)
{
	queue<TreeNode*> queue;
	vector<vector<int>> result;
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
		cout << "The size is " << size << endl;
		vector<int> levelResult;
		for (int i = 0; i < size; i++)
		{
			TreeNode* tmp = queue.front();
			queue.pop();
			levelResult.push_back(tmp->val);
			if (tmp->left) 
			{
				queue.push(tmp->left);
			}
			if (tmp->right) 
			{
				queue.push(tmp->right);
			}
		}
		result.push_back(levelResult);
	}
	return result;
}
