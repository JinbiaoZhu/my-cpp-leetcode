#include "maxDepth.h"
#include<queue>

using namespace std;

int maxDepth(TreeNode* root)
{
    int result = 0;
    vector<vector<int>> global;
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
        vector<int> local;

        for (int i = 0; i < size; i++)
        {
            TreeNode* temp = queue.front();
            queue.pop();
            local.push_back(temp->val);
            if (temp->left) 
            {
                queue.push(temp->left);
            }
            if (temp->right) 
            {
                queue.push(temp->right);
            }
        }

        global.push_back(local);
    }

    result = global.size();
    return result;
}


int maxDepth_v2(TreeNode* root) 
{
    return getDepth(root);
}

// ȷ���ݹ麯�����������
int getDepth(TreeNode* node)
{

    // ȷ����ֹ����
    if (node == nullptr)
    {
        return 0;
    }

    // ȷ���ݹ��߼�
    int left_depth = getDepth(node->left);
    int right_depth = getDepth(node->right);

    int result = 1 + max(left_depth, right_depth);

    return result;
}
