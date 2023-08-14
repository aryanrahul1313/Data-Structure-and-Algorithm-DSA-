#include <bits/stdc++.h> 
class NQueue{
    
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int * next;
    
public:
    NQueue(int n, int s){
        front = new int[n];
        rear = new int[n];

        for(int i=0; i<n; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[s];

        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1; 

        arr = new int[s];
        freespot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // check for overflow
        if(freespot == -1){
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        //check whether first element
        if(front[m-1] == -1){
            front[m-1] = index;
        }
        else{
            // link new element to prev element
            next[rear[m-1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[m-1] = index;

        //push element
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // check underflow condition
        if(front[m-1] == -1){
            return -1;
        }
        
        int index = front[m-1];
        
        front[m-1] = next[index];

        next[index] = freespot;

        freespot = index; 

        return arr[index];
    }
};
