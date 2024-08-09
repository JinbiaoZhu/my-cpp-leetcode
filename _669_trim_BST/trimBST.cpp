#include "trimBST.h"


// ȷ���ݹ麯�����������
TreeNode* trimBST(TreeNode* root, int low, int high)
{
	// ȷ���ݹ麯������ֹ����
	if (root==nullptr)
	{
		return nullptr;
	}
	
	// ȷ���ݹ麯���ĵݹ��߼��ͳ������
	// �����ǰ�Ľڵ�ֵ��������Сֵ��ҪС����ô������������
	if (root->val < low)
	{
		TreeNode* right = trimBST(root->right, low, high);
		return right;
	}

	// �����ǰ�Ľڵ�ֵ���������ֵ��Ҫ����ô������������
	if (root->val > high)
	{
		TreeNode* left = trimBST(root->left, low, high);
		return left;
	}

	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);

	return root;
}
