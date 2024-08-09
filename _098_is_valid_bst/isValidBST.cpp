#include "isValidBST.h"

bool isValidBST(TreeNode* root)
{
    vector<int> result;
    traverseBST(root, result);
    return isSequential(result);
}

// ȷ���ݹ麯���������
void traverseBST(TreeNode* node, vector<int>& result)
{
    // ȷ���ݹ麯����ֹ����
    if (node==nullptr)
    {
        return;
    }

    // ȷ���ݹ麯���ݹ��߼��ͳ������
    if (node->left != nullptr)
    {
        traverseBST(node->left, result);
    }
    result.push_back(node->val);
    if (node->right != nullptr)
    {
        traverseBST(node->right, result);
    }
}

bool isSequential(vector<int> nums)
{
    if (nums.size()==2)
    {
        if (nums[0] < nums[1]) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    vector<int> temp_result;

    for (int i = 1; i < nums.size(); i++)
    {
        temp_result.push_back(
            nums.at(i) - nums.at(i - 1)
        );
    }

    for (int i = 0; i < temp_result.size(); i++)
    {
        if (temp_result.at(i) <= 0) 
        {
            return false;
        }
    }

    return true;
}
