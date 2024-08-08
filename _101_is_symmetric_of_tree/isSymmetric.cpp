#include "isSymmetric.h"

// ȷ�������������
bool compare(TreeNode* left, TreeNode* right)
{
	// ȷ����ֹ����
	if (left == nullptr && right != nullptr)
	{
		return false;
	}
	else if (left != nullptr && right == nullptr)
	{
		return false;
	}
	else if (left == nullptr && right == nullptr)
	{
		return true;
	}
	else if (left->val != right->val)
	{
		return false;
	}

	// ȷ�������߼�
	bool outside = compare(left->left, right->right);
	bool inside = compare(left->right, right->left);
	
	// ȷ�����շ���ֵ
	bool isCompare = outside && inside;
	return isCompare;
}

bool isSymmetric(TreeNode* root)
{
	if (root==nullptr)
	{
		return true;
	}
	return compare(root->left, root->right);
}



