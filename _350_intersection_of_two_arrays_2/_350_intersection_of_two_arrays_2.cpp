#include <iostream>
#include<vector>
#include"intersection.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    vector<int> A = { 1,4,6,5,5,5,5,5 };
    vector<int> B = { 1,2,3,4,5,6,7,8,9,5 };

    vector<int> result = intersection(A, B);
    printVector(result);

    cin.get();
    return 0;
}

