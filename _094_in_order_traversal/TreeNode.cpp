#include "TreeNode.h"

TreeNode::TreeNode(int x)
{
	this->val = x;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode* buildTree(vector<int>& data)
{
    vector<TreeNode*> vecTree(data.size(), NULL);
    TreeNode* root = NULL;
    // 把输入数值数组，先转化为二叉树节点数组
    for (int i = 0; i < data.size(); i++) {
        TreeNode* node = NULL;
        if (data[i] != -1) 
        {
            node = new TreeNode(data[i]); // 用 -1 表示null
        }
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    // 遍历一遍，根据规则左右孩子赋值就可以了
    // 注意这里 结束规则是 i * 2 + 1 < vec.size()，避免空指针
    // 为什么结束规则不能是i * 2 + 2 < arr.length呢?
    // 如果i * 2 + 2 < arr.length 是结束条件
    // 那么i * 2 + 1这个符合条件的节点就被忽略掉了
    // 例如[2,7,9,-1,1,9,6,-1,-1,10] 这样的一个二叉树,最后的10就会被忽略掉
    // 遍历一遍，根据规则左右孩子赋值就可以了

    for (int i = 0; i * 2 + 1 < data.size(); i++) {
        if (vecTree[i] != NULL) {
            // 线性存储转连式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            if (i * 2 + 2 < data.size()) 
            {
                vecTree[i]->right = vecTree[i * 2 + 2];
            }
        }
    }
    return root;
}
