/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

//detecting loop...
Node* floydDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

//finding starting node...
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL){
        return NULL;
    }
    Node* slow = head;

    //here intersection is actually fast pointer with pace of slow pointer
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

//deleting loop...
Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* start = getStartingNode(head);
    if(start == NULL){
        return head;
    }
    Node* temp = start;

    while(temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}
