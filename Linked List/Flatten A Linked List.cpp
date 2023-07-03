#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge two sorted LL
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    while(left != NULL){
        temp->child = left;
        temp = left;
        left = left->child;
    }
    while(right != NULL){
        temp->child = right;
        temp = right;
        right = right->child;
    }

    ans = ans->child;

    return ans;
}


Node* flattenLinkedList(Node* head) 
{
	if(head == NULL){
		return NULL;
	}

	Node* head1 = head;
	Node* head2 = head1->next;
	head1->next = NULL;

	head2 = flattenLinkedList(head2);
	Node* ans = merge(head1, head2);
	return ans;
}
