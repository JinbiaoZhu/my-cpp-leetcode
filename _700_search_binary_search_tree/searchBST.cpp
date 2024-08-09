#include "searchBST.h"

// ȷ���ݹ麯���������
TreeNode* searchBST(TreeNode* root, int val)
{
    // ȷ���ݹ���ֹ����
	if (root==nullptr)
	{
		return nullptr;
	}
	
	// ȷ���ݹ麯���ݹ��߼��ͳ������
	if (root->val == val)
	{
		return root;
	}

	TreeNode* temp = nullptr;

	// ���������������գ��������������н���ֵ��С�����ĸ�����ֵ
	if (root->left && root->val > val)
	{
		temp = searchBST(root->left, val);
	}

	if (root->right && root->val < val)
	{
		temp = searchBST(root->right, val);
	}

	return temp;
}
