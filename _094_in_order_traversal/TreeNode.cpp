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
    // ��������ֵ���飬��ת��Ϊ�������ڵ�����
    for (int i = 0; i < data.size(); i++) {
        TreeNode* node = NULL;
        if (data[i] != -1) 
        {
            node = new TreeNode(data[i]); // �� -1 ��ʾnull
        }
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    // ����һ�飬���ݹ������Һ��Ӹ�ֵ�Ϳ�����
    // ע������ ���������� i * 2 + 1 < vec.size()�������ָ��
    // Ϊʲô������������i * 2 + 2 < arr.length��?
    // ���i * 2 + 2 < arr.length �ǽ�������
    // ��ôi * 2 + 1������������Ľڵ�ͱ����Ե���
    // ����[2,7,9,-1,1,9,6,-1,-1,10] ������һ��������,����10�ͻᱻ���Ե�
    // ����һ�飬���ݹ������Һ��Ӹ�ֵ�Ϳ�����

    for (int i = 0; i * 2 + 1 < data.size(); i++) {
        if (vecTree[i] != NULL) {
            // ���Դ洢ת��ʽ�洢�ؼ��߼�
            vecTree[i]->left = vecTree[i * 2 + 1];
            if (i * 2 + 2 < data.size()) 
            {
                vecTree[i]->right = vecTree[i * 2 + 2];
            }
        }
    }
    return root;
}
