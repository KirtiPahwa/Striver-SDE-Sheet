// Iterative approach:
#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *temp;
    while (head)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

// Recursive approach:
