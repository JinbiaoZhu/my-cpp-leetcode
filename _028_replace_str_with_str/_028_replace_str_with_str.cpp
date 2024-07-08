#include <iostream>
#include"strStr.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    string haystack = "leetcode";
    string needle = "leeto";

    int result = strStr(haystack, needle);

    cout << "result is " << result << endl;

    cin.get();
    return 0;
}
