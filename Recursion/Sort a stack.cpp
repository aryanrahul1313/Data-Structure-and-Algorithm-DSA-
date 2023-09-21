/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int> &s, int num){
    int n = s.size();
    if(n == 0 || s.top() < num){
        s.push(num);
        return;
    }
    
    int val = s.top();
    s.pop();
    insert(s, num);
    s.push(val);
}

void SortedStack :: sort()
{
    int n = s.size();
    //base case
    if(n == 1){
        return;
    }
    int temp = s.top();
    s.pop();
    sort();
    insert(s, temp);
}
