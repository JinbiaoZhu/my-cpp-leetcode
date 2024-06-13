#include <iostream>
#include"MyLinkedList.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int size;

    int A[] = { 1,9,2,8,3,7,4,6,5,5 };
    size = sizeof(A) / sizeof(A[0]);
    MyLinkedList my_linked_list_A(A, size);
    printLinkedList(my_linked_list_A._dummyHead->next);

    int B[] = { 7,4,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
    size = sizeof(B) / sizeof(B[0]);
    MyLinkedList my_linked_list_B(B, size);
    printLinkedList(my_linked_list_B._dummyHead->next);

    MyLinkedList::LinkNode* result = 
        getIntersectionNode(
            my_linked_list_A._dummyHead, 
            my_linked_list_B._dummyHead
        );
    printLinkedList(result);


    cin.get();
    return 0;
}
