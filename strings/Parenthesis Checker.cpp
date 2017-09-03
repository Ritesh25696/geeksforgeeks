
Given an expression string exp, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

 

Input:

The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of a string of expression, in a separate line.

Output:

Print 'balanced' without quotes if pair of parenthesis are balanced else print 'not balanced' in a separate line.


Constraints:

1 ≤ T ≤ 100
1 ≤ |s| ≤ 100


Example:

Input:
3
{([])}
()
()[]

Output:
balanced
balanced
balanced
***********************************************************************************************************
#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    string s;
	    cin>>s;
	    stack<char> st;
	    bool done = false;
	    for(int i=0 ; i<s.length() ; i++){

	        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
	        st.push(s[i]);
	        else{
	            if(!st.empty()){
	            if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')){
	            st.pop();}
	            else{
	                cout<<"not balanced"<<endl;
	                done = true;
	                break;
	            }
	            }
	            else{
	                cout<<"not balanced"<<endl;
	                done = true;
	                break;
	            }
	        }
	    }
	    if(st.empty() && !done){
	        cout<<"balanced"<<endl;
	        done = true;
	    }
	    if(!done){
	        cout<<"not balanced"<<endl;
	    }
	}
	return 0;
}
