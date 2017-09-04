Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

***************************************************************************************************
#include<iostream>
#include<algorithm>
using namespace std;
;
int LCS(string a , string b){
    int n = a.length() , m = b.length();
    int arr[n+1][m+1];
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(i ==0 || j==0)
            arr[i][j] = 0;
            else if(a[i-1] == b[j-1])
            arr[i][j] = arr[i-1][j-1]+1;
            else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[n][m];
}

int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    string s;
	    cin>>s;
	    string s2 = s;
	    reverse(s2.begin(),s2.end());
	    int k = LCS(s , s2);
	    cout<<s.length()-k<<endl;
	}
	return 0;
}
