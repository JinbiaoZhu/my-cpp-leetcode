#include <iostream>
#include "_intersection_of_two_arrays.h"


int main()
{
    std::cout << "Hello World!\n";

    int array_1[] = {1,2,3,4,5,6,7,8,9,0};
    int array_2[] = {11,13,17,19};

    int size_1 = sizeof(array_1) / sizeof(array_1[0]);
    int size_2 = sizeof(array_2) / sizeof(array_2[0]);

    vector<int> result = intersection_of_two_arrays(array_1, size_1, array_2, size_2);
    printSet(result);

    cin.get();
    return 0;
}