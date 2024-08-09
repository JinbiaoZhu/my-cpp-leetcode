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

// ȷ���ݹ麯�����������
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	// ȷ���ݹ���ֹ����
	if (postorder.size()==0)
	{
		return nullptr;
	}


	// ȷ���ݹ��߼�
	// step1. �Ӻ��������е����һ���ҵ��зֵ�
	int _val = postorder.at(postorder.size() - 1);
	TreeNode* root = new TreeNode(_val);
	if (postorder.size()==1)
	{
		return root;
	}

	// step2. ���ݺ����зֵ㣬�з�����
	int secIndex = -1;
	for (int idx = 0; idx < inorder.size(); idx++)
	{
		if (inorder.at(idx) == _val) 
		{
			secIndex = idx;
			break;
		}
	}

	// step3. ���з�����, ע���º����� +1 ����
	vector<int> left_part(inorder.begin(), inorder.begin() + secIndex);
	vector<int> right_part(inorder.begin() + secIndex + 1, inorder.end());

	// step4. ���µ����������в��з�
	postorder.resize(postorder.size() - 1);
	vector<int> left_postorder(postorder.begin(), postorder.begin() + left_part.size());
	vector<int> right_postorder(postorder.begin() + left_part.size(), postorder.end());

	// step5. ���еݹ�
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
