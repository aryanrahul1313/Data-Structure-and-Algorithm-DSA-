void insertAtBottom(stack<int> &s, int element){
    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    //RECURSIVE CALL
    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //RECURSIVE CALL
    reverseStack(stack);

    insertAtBottom(stack, num);
}
