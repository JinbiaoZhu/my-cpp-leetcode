#pragma once
#include<vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* rigth;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
};

TreeNode* buildTree(vector<int>& data);