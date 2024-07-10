#include <iostream>
#include"MyStack.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    MyStack* obj = new MyStack();

    obj->push(10);
    obj->push(20);
    obj->push(30);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    if (param_4)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }

    cin.get();
    return 0;
}
