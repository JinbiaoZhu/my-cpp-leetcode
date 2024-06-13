#include <iostream>
#include"MyLinkedList.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int arr[10] = { 1,9,2,8,3,7,4,6,5,5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int pos = 8;

    MyLinkedList my_linked_list(arr, size, pos);
    printLinkedList(my_linked_list._dummyHead);
    MyLinkedList::LinkNode* result = my_linked_list.detectCircle();
    printLinkedList(result);

    cin.get();
    return 0;
    
}
