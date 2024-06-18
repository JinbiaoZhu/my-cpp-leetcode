#include <iostream>
#include<vector>
#include"reverse_string.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<char> s = { 'h','e','l','l','o'};
    reverseString(s);

    for (int i = 0; i < s.size(); i++) 
    {
        cout << s[i] << " ";
    }

    cin.get();
    return 0;
}
