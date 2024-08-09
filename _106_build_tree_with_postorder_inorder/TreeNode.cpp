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

// 确定递归函数的输入输出
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	// 确定递归终止条件
	if (postorder.size()==0)
	{
		return nullptr;
	}


	// 确定递归逻辑
	// step1. 从后序数组中的最后一个找到切分点
	int _val = postorder.at(postorder.size() - 1);
	TreeNode* root = new TreeNode(_val);
	if (postorder.size()==1)
	{
		return root;
	}

	// step2. 根据后序切分点，切分中序
	int secIndex = -1;
	for (int idx = 0; idx < inorder.size(); idx++)
	{
		if (inorder.at(idx) == _val) 
		{
			secIndex = idx;
			break;
		}
	}

	// step3. 先切分中序, 注意新后序有 +1 操作
	vector<int> left_part(inorder.begin(), inorder.begin() + secIndex);
	vector<int> right_part(inorder.begin() + secIndex + 1, inorder.end());

	// step4. 重新调整后序序列并切分
	postorder.resize(postorder.size() - 1);
	vector<int> left_postorder(postorder.begin(), postorder.begin() + left_part.size());
	vector<int> right_postorder(postorder.begin() + left_part.size(), postorder.end());

	// step5. 进行递归
	root->left = buildTree(left_part, left_postorder);
	root->right = buildTree(right_part, right_postorder);

	return root;
}

vector<int> traverse(TreeNode* root)
{
	vector<int> result;
	queue<TreeNode*> queue;

	if (root==nullptr)
	{
		return result;
	}

	queue.push(root);
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
