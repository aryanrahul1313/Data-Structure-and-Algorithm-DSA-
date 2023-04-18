#include <bits/stdc++.h> 
void reverse(string& str,int n){ 
	//& is used (pass by reference)
	if(n >= (str.length()-n-1)){
		return;
	}

	swap(str[n], str[str.length()-n-1]);
	n++;

    reverse(str,n);
}

string reverseString(string str)
{
	reverse(str,0);
	return str;
}
