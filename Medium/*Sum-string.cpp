Given a string of digits, the task is to check if it is a ‘sum-string’. A string S is called a sum-string if a rightmost substring can be written as sum of two substrings before it and same is recursively true for substrings before it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string S as input.

Output:
For each test case, print "1", if the string is sum-string else print "0".

Constraints:
1<=T<=100
1<=S<=105

Example:
Input:
3
12243660
1111112223
2368

Output:
1
1
0

Explanation:

 In 1st test case 
"12243660" is a sum string. 
As we can get, 24 + 36 = 60 & 12 + 24 = 36
 In 2nd test case
"1111112223" is a sum string. 
As we can get, 111+112 = 223 & 1+111 = 112
************************************************************************************************************************************
#include<iostream>
using namespace std;

string string_sum(string str1, string str2)
{
    if (str1.size() < str2.size())
       swap(str1, str2);
 
    int m = str1.size();
    int n = str2.size();
    string ans = "";
 
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int ds = ((str1[m - 1 - i] - '0') +
                  (str2[n - 1 - i] - '0') +
                  carry) % 10;
 
        carry = ((str1[m - 1 - i] - '0') +
                 (str2[n - 1 - i] - '0') +
                 carry) / 10;
 
        ans = char(ds + '0') + ans;
    }
 
    for (int i = n; i < m; i++) {
        int ds = (str1[m - 1 - i] - '0' +
                  carry) % 10;
        carry = (str1[m - 1 - i] - '0' +
                 carry) / 10;
        ans = char(ds + '0') + ans;
    }
 
    if (carry)
        ans = char(carry + '0') + ans;
    return ans;
}


bool util(string s , int st , int len1 , int len2){
    string s1 = s.substr(st,len1);
    string s2 = s.substr(st+len1,len2);
    string s3 = string_sum(s1,s2);
    int len3 = s3.length();
    if(s.length() < st+len1+len2+len3)return false;
    if(s3 == s.substr(st+len1+len2,len3)){
        if(st+len1+len2+len3 == s.length())return true;
        return util(s,st+len1,len2,len3);
    }
    return false;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    bool done = false;
	    for(int i=1; i<s.length() && !done; i++){
	        for(int j=1; j+i<s.length() ; j++){a
	           if (util(s,0,i,j)){
	               cout<<1<<endl;
	               done = true;
	               break;
	           }
	        }
	    }
	    if(!done)cout<<0<<endl;
	}
	return 0;
}
