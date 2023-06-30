#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* solve(Node<int>* first, Node<int>* second){
    //if only one node is present in first list
    if(first->next == NULL){
        first->next = second;
        return first;
    }

    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        
        if(curr2->data >= curr1->data && curr2->data <= next1->data){
            //node addition in between the first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //curr1 or nex1 ko aage badhao...
            curr1 = next1;
            next1 = next1->next;
            
            //important case
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    //hmesha second wale ko bich me insert krenge first ke nodes me
    if(first->data <= second->data){
        solve(first,second);
    }
    else{
        solve(second,first);
    }
}
