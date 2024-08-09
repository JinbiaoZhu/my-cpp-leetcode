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


// ȷ���ݹ麯������������
TreeNode* buildTree(vector<int> preorder, vector<int> inorder)
{
	// ȷ���ݹ麯������ֹ����
	if (preorder.size()==0)
	{
		return nullptr;
	}

	// ȷ���ݹ麯���ĵݹ��߼��ͳ������
	// step1. ��ǰ���ҵ����ڵ�
	int father_node_val = preorder.at(0);
	TreeNode* father_node = new TreeNode(father_node_val);

	// step2. ʹ�ø��ڵ�������ڵ�
	// step2-1. ��ȡ���λ��
	int secIndex = -1;
	for (int i = 0; i < inorder.size(); i++)
	{
		if (inorder.at(i) == father_node_val) 
		{
			secIndex = i;
			break;
		}
	}
	// step2-2. �������ڵ�
	vector<int> left_inorder(
		inorder.begin(), inorder.begin() + secIndex
	);
	vector<int> right_inorder(
		inorder.begin() + secIndex + 1, inorder.end()
	);
	// step2-3. ����ǰ��ڵ�
	vector<int> new_preorder(preorder.begin() + 1, preorder.end());
	// step2-4. ���ǰ��ڵ�
	vector<int> left_preorder(
		new_preorder.begin(), new_preorder.begin() + left_inorder.size()
	);
	vector<int> right_preorder(
		new_preorder.begin() + left_inorder.size(), new_preorder.end()
	);

	// step3. ��ʼ�ݹ�
	father_node->left = buildTree(left_preorder, left_inorder);
	father_node->right = buildTree(right_preorder, right_inorder);

	return father_node;
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


