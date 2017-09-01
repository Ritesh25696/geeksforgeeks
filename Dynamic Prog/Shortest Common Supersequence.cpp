Given two strings str1 and str2, find the shortest common shortest common subsequence of the two strings.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case contains two space separated strings.

Output:
Output the length of the shortest common supersequence.

Constraints:
1<=T<=100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
******************************************************************************************************************************************
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    string s1,s2;
	    cin>>s1>>s2;
	    int res[s1.length()+1][s2.length()+1];
	    for(int i=0 ; i<=s1.length() ; i++){
	        res[i][0] = i;
	    }
	    for(int i=0 ; i<=s2.length() ; i++){
	        res[0][i] = i;
	    }
	    for(int i=1 ; i<=s1.length(); i++){
	        for(int j=1 ; j<=s2.length(); j++){
	            if(s1[i-1] == s2[j-1])
	            res[i][j] = res[i-1][j-1]+1;
	            else 
	            res[i][j] = min(res[i-1][j],res[i][j-1])+1;
	        }
	    }
	    cout<<res[s1.length()][s2.length()]<<endl;
	}
	return 0;
}
