#include "getMinimumDifference.h"

int getMinimumDifference(TreeNode* root)
{
    vector<long long int> result;
    inOrderTraverse(root, result);
    return get_minimum_difference(result);
}

// 确定递归函数的输入输出条件
void inOrderTraverse(TreeNode* node, vector<long long int>& nums)
{
    // 确定递归函数的终止条件
    if (node==nullptr)
    {
        return;
    }

    // 确定递归函数的递归逻辑和常规输出
    if (node->left)
    {
        inOrderTraverse(node->left, nums);
    }
    nums.push_back(node->val);
    if (node->right)
    {
        inOrderTraverse(node->right, nums);
    }
}

int get_minimum_difference(vector<long long int> nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }

    if (nums.size() == 2)
    {
        return nums.at(1) - nums.at(0);
    }

    long long int slow_index = 0;
    long long int fast_index = 1;
    long long int temp_difference = nums.at(fast_index) - nums.at(slow_index);
    for (fast_index; fast_index < nums.size(); fast_index++, slow_index++)
    {
        if (nums.at(fast_index) - nums.at(slow_index) <= temp_difference)
        {
            temp_difference = nums.at(fast_index) - nums.at(slow_index);
        }
    }

    return temp_difference;
}
