Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.


Output:
Coreesponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1<=T<=50
1<= Length(str1) <= 100
1<= Length(str2) <= 100
 

Example:
Input:
1
4 5
geek gesek

Output:
1
**********************************************************************************************************************************************************8

#include<iostream>

using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k= 0 ; k<t ; k++){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    int res[n+1][m+1];
	    for(int i=0 ;i<=n ; i++){
	        res[i][0] = i;
	    }
	    for(int i=0 ; i<=m ; i++){
	        res[0][i] = i;
	    }
	    for(int i=1 ; i<=n ; i++){
	        for(int j=1 ; j<=m ; j++){
	            if(s1[i-1] == s2[j-1]){
	                res[i][j] = res[i-1][j-1];
	            }
	            else {
	                res[i][j] = min(res[i-1][j],min(res[i][j-1],res[i-1][j-1]))+1;
	            }
	        }
	    }
	    cout<<res[n][m]<<endl;
	}
	return 0;
}
