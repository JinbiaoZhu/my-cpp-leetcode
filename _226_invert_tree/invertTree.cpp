#include "invertTree.h"
#include<queue>

// 确定输入输出
TreeNode* invertTree(TreeNode* root)
{
    // 确定终止条件
    if (root == nullptr) 
    {
        return root;
    }

    // 确定递推逻辑
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    // 确定返回值
    return root;
}

vector<int> traverseTree(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> queue;

    if (root == nullptr) 
    {
        return result;
    }
    else
    {
        queue.push(root);
    }

    while (!queue.empty())
    {
        int size = queue.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode* temp = queue.front();
            queue.pop();
            result.push_back(temp->val);

            if (temp->left) 
            {
                queue.push(temp->left);
            }
            if (temp->right) 
            {
                queue.push(temp->right);
            }
        }
    }

    return result;
}
