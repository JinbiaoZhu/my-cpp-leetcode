#include <iostream>
#include"reverse_string.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    string s = "using namespace std;";
    s = reverseWords(s);

    cout << s << endl;

    cin.get();
    return 0;
}
