#include "countNodes.h"
#include<iostream>

using namespace std;

// ȷ���ݹ麯�����������
int getCounts_v1(TreeNode* node)
{
	// ȷ���ݹ���ֹ����
	if (node == nullptr)
	{
		return 0;
	}

	// ȷ���ݹ��߼������
	int left_counts = getCounts_v1(node->left);
	int right_counts = getCounts_v1(node->right);

	return 1 + left_counts + right_counts;
}

// ȷ���ݹ麯�����������
int getCounts_v2(TreeNode* node)
{
	// ȷ���ݹ���ֹ����: �ս����� 0 
	if (node == nullptr)
	{
		return 0;
	}

	TreeNode* left = node->left;
	TreeNode* right = node->right;
	int left_depth = 0;
	int right_depth = 0;

	while (left)
	{
		left = left->left;
		left_depth++;
	}
	while (right)
	{
		right = right->right;
		right_depth++;
	}
	if (left_depth == right_depth)
	{
		return (2<< left_depth)-1;
	}

	return 1 + getCounts_v2(node->left) + getCounts_v2(node->right);
}

int isRootOfACompleteTree(TreeNode* node)
{
	int left_depth = 0;
	int right_depth = 0;

	while (node->left)
	{
		node = node->left;
		left_depth++;
	}
	while (node->right)
	{
		node = node->right;
		right_depth++;
	}
	if (left_depth == right_depth)
	{
		return left_depth;
	}
	else
	{
		return -1;
	}
}
