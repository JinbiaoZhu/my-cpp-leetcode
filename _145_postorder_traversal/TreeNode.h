#ifndef TREENODE_H
#define TREENODE_H
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
};

TreeNode* buildTree(vector<int> data, int index);
#endif // TREENODE_H