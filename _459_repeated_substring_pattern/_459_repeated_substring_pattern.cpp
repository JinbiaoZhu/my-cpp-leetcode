// _459_repeated_substring_pattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"repeatedSubstringPattern.h"

int main()
{
    std::cout << "Hello World!\n";

    string s = "abacabac";

    bool result = repeatedSubstringPattern(s);

    if (result == true) 
    {
        cout << "OK" << endl;
    }
    if (result == false) 
    {
        cout << "Not OK" << endl;
    }
    
    cin.get();
    return 0;
}
