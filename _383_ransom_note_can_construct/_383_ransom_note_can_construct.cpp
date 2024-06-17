#include <iostream>
#include<string>
#include"canConstruct.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    string A = "aa";
    string B = "b";

    bool result = canConstruct_solution2(A, B);
    if (result) { cout << "Successfully." << endl; }
    else { cout << "Not successfully." << endl; }

    cin.get();
    return 0;
}
