#pragma once
#include<vector>
#include<string>

using namespace std;

vector<vector<string>> partition(string s);
void backtrack(vector<vector<string>>& result, vector<string>& single_result, const string& s, int position);
bool isPalindrome(const string& s, int left, int right);