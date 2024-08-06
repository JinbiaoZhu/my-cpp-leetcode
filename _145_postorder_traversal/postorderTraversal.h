#pragma once
#include<vector>
#include"TreeNode.h"

using namespace std;

vector<int> postorderTraversal(TreeNode* root);
void traversalSingleNode(TreeNode* current, vector<int>& result);
