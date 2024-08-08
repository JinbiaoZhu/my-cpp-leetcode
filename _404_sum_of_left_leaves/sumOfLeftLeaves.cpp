#include "sumOfLeftLeaves.h"

// ȷ���ݹ麯������������
int sumOfLeftLeaves(TreeNode* root)
{
    // ȷ���ݹ麯������ֹ����
	if (root==nullptr)
	{
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) 
	{
		return 0;
	}

	// ȷ�������ݹ��߼��ͷ����߼�
	int left_sum = 0; int right_sum = 0;
	if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) 
	{
		left_sum = root->left->val;
	}
	else
	{
		left_sum = sumOfLeftLeaves(root->left);
	}

	right_sum = sumOfLeftLeaves(root->right);

	return left_sum + right_sum;
}
