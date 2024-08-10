#include "letterCombinations.h"

vector<string> letterCombinations(string digits)
{
	vector<string> total_result;
	string single_result;
	int startIndex = 0;
	backtrack(total_result, single_result, digits, startIndex);
	return total_result;
}

// 确定回溯函数的输入和输出
void backtrack(vector<string>& total_result, string& single_result, string& digits, int startIndex) 
{
    // 确定回溯函数的终止条件
	if (startIndex >= digits.length())
	{
		total_result.push_back(single_result);
		return;
	}

	// 确定回溯函数的回溯逻辑
	string key_string = charDigit2String(char(digits.at(startIndex)));
	
	for (int i = 0; i < key_string.length(); i++)
	{
		single_result.push_back(key_string.at(i));
		backtrack(total_result, single_result, digits, startIndex + 1);
		single_result.pop_back();
	}
}

string charDigit2String(char digits)
{
	int number = digits - '0';  // 转换成和字符一样的顺序
	if (number == 2){return "abc";}
	if (number == 3){return "def";}
	if (number == 4){return "ghi";}
	if (number == 5){return "jkl";}
	if (number == 6){return "mno";}
	if (number == 7){return "pqrs";}
	if (number == 8){return "tuv";}
	if (number == 9){return "wxyz";}
}