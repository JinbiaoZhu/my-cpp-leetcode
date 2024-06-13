#include <iostream>
#include "MyLinkedList.h"\

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int arr[10] = { 1,9,2,8,3,7,4,6,5,5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    MyLinkedList my_linkedlist(arr, size);
    my_linkedlist.printLinkedList();
    my_linkedlist.removeNthElements(4);
    my_linkedlist.printLinkedList();

    cin.get();
    return 0;
}


