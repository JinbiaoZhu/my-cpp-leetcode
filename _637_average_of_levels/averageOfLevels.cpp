#include "averageOfLevels.h"
#include"TreeNode.h"
#include<vector>
#include<queue>

using namespace std;

vector<float> averageOfLevels(TreeNode* root)
{
    vector<float> result;
    queue<TreeNode*> queue;

    if (root==nullptr) 
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
        float sum = 0.0;

        for (int i = 0; i < size; i++)
        {
            TreeNode* tmp = queue.front();
            queue.pop();
            sum += tmp->val;
            if (tmp->left) 
            {
                queue.push(tmp->left);
            }
            if (tmp->right)
            {
                queue.push(tmp->right);
            }
        }

        result.push_back(sum / size);
    }

    return result;
}
