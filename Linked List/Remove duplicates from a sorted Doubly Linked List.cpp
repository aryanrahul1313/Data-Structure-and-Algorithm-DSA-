/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    if(head == NULL){  //empty list
        return NULL;
    }
    //non empty list
    Node* curr = head;

    while(curr != NULL){
        if((curr->next != NULL) && curr->data == curr->next->data){
            Node* forward = curr->next->next;
            Node* toDelete = curr->next;
            delete(toDelete);
            curr->next = forward;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}
