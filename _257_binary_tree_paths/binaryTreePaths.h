#pragma once
#include<vector>
#include<string>
#include"TreeNode.h"

using namespace std;

void traverse(TreeNode* node, vector<int>& path, vector<string>& path_string);
vector<string> getPath(TreeNode* root);