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

***********************************************************************************************************************************************
#include<iostream>
#include<map>
using namespace std;
int main()
 {
	map<char , int> value;
	value['I'] = 1;
	value['V'] = 5;
	value['X'] = 10;
	value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;
    int t;
    cin>>t;
    for(int ct=0 ; ct<t; ct++){
        string s;
        cin>>s;
        int n = s.length();
        int res = 0;
        bool done = false;
    if(s.length() == 0 ){cout<<0<<endl;done = true;}
    else if(s.length() == 1) {done = true;cout<<value[s[0]]<<endl;}
        else{
            for(int i=0 ; i<s.length()-1 ; i++){
            if(value[s[i]]  < value[s[i+1]]){
                res+=(value[s[i+1]]-value[s[i]]);
                i++;
            }
            else{
                res+=value[s[i]];
            }
        }
        if(value[s[n-2]] >= value[s[n-1]])
        res+=value[s[n-1]];

        cout<<res<<endl;
    }}
	return 0;
}
