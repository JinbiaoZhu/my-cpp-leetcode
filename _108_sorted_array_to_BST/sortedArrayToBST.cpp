#include "sortedArrayToBST.h"

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	return sorted_Array_To_BST(nums, 0, nums.size()-1);
}

// ȷ���ݹ麯������������
TreeNode* sorted_Array_To_BST(vector<int>& nums, int left, int right) 
{
	// ȷ���ݹ麯������ֹ����
	if (left>right)
	{
		return nullptr;
	}

	// left <= right
	// ȷ���ݹ��߼��ͳ������
	if (right-left==0)
	{
		TreeNode* node = new TreeNode(nums.at(right));
		return node;
	}

	if (right-left == 1)
	{
		TreeNode* small = new TreeNode(nums.at(left));
		TreeNode* large = new TreeNode(nums.at(right));
		large->left = small;
		return large;
	}

	int mid = (left + right) / 2;  // ����������������ȡ��, 1.732 ���Ƴ� 1
	TreeNode* root = new TreeNode(nums.at(mid));

	root->left = sorted_Array_To_BST(nums, left, mid - 1);
	root->right = sorted_Array_To_BST(nums, mid + 1, right);

	return root;
}
