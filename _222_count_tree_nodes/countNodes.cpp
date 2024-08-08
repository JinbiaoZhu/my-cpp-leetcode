#include "countNodes.h"
#include<iostream>

using namespace std;

// 确定递归函数的输入输出
int getCounts_v1(TreeNode* node)
{
	// 确定递归终止条件
	if (node == nullptr)
	{
		return 0;
	}

	// 确定递归逻辑与输出
	int left_counts = getCounts_v1(node->left);
	int right_counts = getCounts_v1(node->right);

	return 1 + left_counts + right_counts;
}

// 确定递归函数的输入输出
int getCounts_v2(TreeNode* node)
{
	// 确定递归终止条件: 空结点等于 0 
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
