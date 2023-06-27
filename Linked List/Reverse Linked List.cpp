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

LinkedListNode<int>* reverse(LinkedListNode<int>* &head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int>* chotahead = reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;

    return chotahead;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    
    return reverse(head);
}
