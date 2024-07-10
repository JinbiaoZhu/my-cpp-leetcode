#include <iostream>
#include"MyQueue.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    MyQueue* obj = new MyQueue();
    obj->push(10);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();

    cin.get();
    return 0;
}
