#include "mergeTrees.h"

// 确定递归函数的输入输出
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
{
	// 确定递归函数的终止条件
	if ( root1 == nullptr && root2 == nullptr )
	{
		return nullptr;
	}

	// 确定递归函数的逻辑的常规输出
	TreeNode* temp = new TreeNode();
	if (root1 != nullptr && root2 != nullptr)
	{ 
		temp = new TreeNode(root1->val + root2->val); 

		// 左子树
		if (root1->left != nullptr && root2->left != nullptr)
		{
			temp->left = mergeTrees(root1->left, root2->left);
		}
		else if (root1->left != nullptr && root2->left == nullptr)
		{
			temp->left = root1->left;
		}
		else
		{
			temp->left = root2->left;
		}

		// 右子树
		if (root1->right != nullptr && root2->right != nullptr)
		{
			temp->right = mergeTrees(root1->right, root2->right);
		}
		else if (root1->right != nullptr && root2->right == nullptr)
		{
			temp->right = root1->right;
		}
		else
		{
			temp->right = root2->right;
		}
	}

	if (root1 != nullptr && root2 == nullptr)
	{ 
		temp = new TreeNode(root1->val); 
	}

	if (root1 == nullptr && root2 != nullptr)
	{ 
		temp = new TreeNode(root2->val); 
	}

	return temp;
}
