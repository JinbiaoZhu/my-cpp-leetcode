#include "rob.h"

int rob(treeNode* root)
{
	vector<int> result = robInTree(root);
	return max(result[0], result[1]);
}


// 1. 确定递归函数返回值和输入参数
// 1. vector<int> {3 ,5} 下标为 0 记录不偷该节点所得到的的最大金钱
//                       下标为 1 记录偷该节点所得到的的最大金钱。
vector<int> robInTree(treeNode* current) 
{
	// 2. 确定递归函数终止条件
	if (current == nullptr)
	{
		return vector<int> {0, 0};
	}

	// 3. 确定单层搜索过程: 后序遍历 + 动态规划
	vector<int> left_result = robInTree(current->left);
	vector<int> right_result = robInTree(current->right);

	// 4. 当前节点偷 + 相邻两个子节点不偷
	int val1 = current->nodeValue + left_result[0] + right_result[0];
	// 4. 当前节点不偷 + 相邻两个子节点偷最大值, 两个子节点可偷可不偷
	int val2 = max(left_result[0], left_result[1]) + max(right_result[0], right_result[1]);

	return vector<int> {val2, val1};
}
