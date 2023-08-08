#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stack, int n){
	//base case
	if(stack.empty() || (!stack.empty() && stack.top() < n)){
		stack.push(n);
		return;
	}

	int num = stack.top();
	stack.pop();

	//RECURSIVE CALL
	sortedInsert(stack, n);
	stack.push(num);
}

void sortStack(stack<int> &stack)
{
	// base case
	if(stack.empty()){
		return;
	}
	
	int num = stack.top();
	stack.pop();

	//RECURSIVE CALL
	sortStack(stack);

	sortedInsert(stack, num);
}
