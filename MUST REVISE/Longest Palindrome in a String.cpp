Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[ i . . . . j ] where 0 ≤ i ≤ j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Input:

The first line of input consists number of the test cases. The following T lines consist of a string each.


Output:

In each separate line print the longest palindrome of the string given in the respective test case.


Constraints:

1 ≤T≤ 100
1 ≤ str≤ 100


Example:

Input:

1
aaaabbaa

Output:

aabbaa

**For More Examples Use Expected Output**
************************************************************************************************************************************************************************************
#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    for(int ct=0 ; ct<t; ct++){
        string s;
        cin>>s;
        int n = s.length(), len = s.length();
        bool done = false;
       
        while(len>0 && !done){
            int j=0;
            while(j+len <=n){
                int st = j , end = j+len-1;
               while(st < end){
               if(s[st] != s[end]) break;
               st++; end--;
                }
                if(st  >= end ){
                    cout<<s.substr(j,len);
                    done = true;
                    break;
                }
                j++;
            }
            len--;
        }
        cout<<endl;
    }
	return 0;
}
