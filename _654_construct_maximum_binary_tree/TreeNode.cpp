#include "TreeNode.h"
#include<queue>

using namespace std;

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

// 确定递归函数输入输出
TreeNode* buildTree(vector<int> data)
{
	// 确定递归函数终止条件
	if (data.size()==0)
	{
		return nullptr;
	}
	
	// 确定递归函数递归逻辑
	// step1. "创建一个根节点，其值为 nums 中的最大值。"
	int max_value = maxValue(data);
	TreeNode* root = new TreeNode(max_value);

	// step2. "对数据进行划分"
	int secIndex;
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) == max_value) 
		{
			secIndex = i;
			break;
		}
	}
	vector<int> left_data(data.begin(), data.begin() + secIndex);
	vector<int> right_data(data.begin() + secIndex + 1, data.end());

	// step3. "创建左节点和右节点"
	root->left = buildTree(left_data);
	root->right = buildTree(right_data);

	return root;
}

int maxValue(vector<int> data)
{
	int temp_max = -1 * (2 << 16);
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) >= temp_max) 
		{
			temp_max = data.at(i);
		}
	}

	return temp_max;
}

vector<int> traverse(TreeNode* root)
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
