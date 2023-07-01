//Approach 1
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>

class Solution{
  private:
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        
        while(s <= e){
            if(arr[s] != arr[e]){
            return 0;
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        
        Node* temp = head;
        
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }
};



//Approach 2
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  private:
    Node* reverse(Node* head){
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
    
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next == NULL){
            return true;
        }
        //Step1: find middle
        Node* middle = getMid(head);
        
        //Step2: reverse list after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        //Step3: compare both half
        Node* head1 = head;
        Node* head2 = middle->next;
        
        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
            
        }
        //Step4: repeat step 2 (optional)
        temp = middle->next;
        middle->next = reverse(temp);
        
        return true;
    }
};
