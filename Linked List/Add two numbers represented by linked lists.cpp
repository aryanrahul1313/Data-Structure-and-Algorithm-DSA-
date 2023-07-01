/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    void insertAtTail(struct Node* &head, struct Node* &tail, int value){
        Node* temp = new Node(value);
        //empty list
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{  //non-empty list
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){
                val1 = first->data;
            }
            int val2 = 0;
            if(second != NULL){
                val2 = second->data;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            //create node and add digit in ans
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            if(first != NULL){
                first = first->next;
            }
            if(second != NULL){
                second = second->next;
            }
        }
        return ansHead;
    }
    
    Node* reverse(struct Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //Step1: reverse both linked list
        first = reverse(first);
        second = reverse(second);
        
        //Step2: add bith linked list
        Node* ans = add(first,second);
        
        //Step3: reverse ans
        ans = reverse(ans);
        
        return ans;
    }
};
