#include <iostream>
#include"MyLinkedList.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int arr[10] = { 1,9,2,8,3,7,4,6,5,5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int get_index = 8;

    MyLinkedList my_linked_list(arr, size);
    my_linked_list.printLinkedList();
    int result = my_linked_list.get(get_index);
    cout << "The index " << get_index << " is value: " << result << "." << endl;
    my_linked_list.addAtHead(666);
    my_linked_list.printLinkedList();
    my_linked_list.addAtTail(999);
    my_linked_list.printLinkedList();
    my_linked_list.addAtIndex(888, 4);
    my_linked_list.printLinkedList();
    my_linked_list.deletaAtIndex(6);
    my_linked_list.printLinkedList();

    cin.get();
    return 0;
}

