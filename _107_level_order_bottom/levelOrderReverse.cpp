#include "levelOrderReverse.h"
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> levelOrderReverse(TreeNode* root)
{
    vector<vector<int>> result;
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
        vector<int> tmpResult;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            tmpResult.push_back(node->val);
            if (node->left) 
            {
                queue.push(node->left);
            }
            if (node->right)
            {
                queue.push(node->right);
            }
        }
        result.push_back(tmpResult);
    }
    reverse(result.begin(), result.end());
    return result;
}
