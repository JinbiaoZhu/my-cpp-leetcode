#pragma once
#include<vector>
#include"TreeNode.h"

using namespace std;

vector<int> inorderTraversal(TreeNode* root);
void singleNodeTraversal(TreeNode* node, vector<int>& result);
vector<int> inorderTraversalforStack(TreeNode* root);
vector<int> inorderTraversalforStackv2(TreeNode* root);