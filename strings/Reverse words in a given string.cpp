Given a String of length N reverse the words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. Each case contains a string containing spaces and characters.
 

Output:
For each test case, output a single line containing the reversed String.

Constraints:
1<=T<=20
1<=Lenght of String<=2000


Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr

****************************************************************************************************************************************************

#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    string s;
	    cin>>s;
	    string s2 = "";
	    stack<string> st;
	    for(int i=0 ; i<s.length() ; i++){
	        if(s[i] == '.'){
	            st.push(s2);
	            s2 = "";
	            continue;
	        }
	        s2+=s[i];
	    }
	    if(s2.length()>0)
	    st.push(s2);
	    string res = "";
	    while(!st.empty()){
	        res+=st.top();
	        res+=".";
	        st.pop();
	    }
	    res.erase(res.length()-1);
	    cout<<res<<endl;
	}
	return 0;
}
