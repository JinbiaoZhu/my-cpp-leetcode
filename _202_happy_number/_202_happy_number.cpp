#include <iostream>
#include"is_happy_number.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    int number_to_test = 6;
    bool result = isHappy(number_to_test);
    if (result) { cout << "The number: " << number_to_test << " is an HappyNumber."; }
    else { cout << "The number: " << number_to_test << " is not an HappyNumber."; }

    cin.get();
    return 0;
}
