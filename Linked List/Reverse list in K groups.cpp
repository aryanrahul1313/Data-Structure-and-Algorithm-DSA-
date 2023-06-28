#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL){
        return NULL;
    }
    //Step1: to reverse first K nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    //Step2: Recursion dekh lega
    if(forward != NULL){
        head->next = kReverse(forward, k);
    }     
    //Step3: Return prev
    return prev;       
}
