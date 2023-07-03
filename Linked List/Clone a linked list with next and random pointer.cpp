class Solution
{
    private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Step1: create a clone of LL
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp->next;
        }
        
        //Step2: add clone nodes in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* forward = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = forward;
            
            forward = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = forward;
        }
        
        //Step3: copy random pointer
        temp = head;
        
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
                /*
                if(temp->arb != NULL){
                    temp->next->arb = temp->arb->next;
                }
                else{
                    temp->next = temp->arb;
                }
                */
            }
            temp = temp->next->next;
        }
        
        //Step4: revert changes in step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }

};
