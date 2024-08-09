#include"lowestCommonAncestor.h"


// ע��: �����Ŀ�Ķ������Ƕ���������
// ȷ���ݹ麯������������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	// ȷ����ֹ����
	if (root == nullptr)
	{
		return root;
	}

	// ȷ���ݹ��߼��ͳ������
	if ((p->val - root->val) * (q->val - root->val) <= 0)
	{
		return root;
	}

	if (p->val > root->val && q->val > root->val)
	{
		return lowestCommonAncestor(root->right, p, q);
	}

	if (p->val < root->val && q->val < root->val)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	
	return nullptr;
}