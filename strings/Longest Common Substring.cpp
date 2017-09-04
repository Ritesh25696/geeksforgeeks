Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = "GeeksforGeeks", y = "GeeksQuiz"
Output : 5
The longest common substring is "Geeks" and is of
length 5.

Input : X = "abcdxyz", y = "xyzabcd"
Output : 4
The longest common substring is "abcd" and is of
length 4.

Input : X = "zxabcdezy", y = "yzabcdezx"
Output : 6
The longest common substring is "abcdez" and is of
length 6.
 

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string X and Y respectively
The next two lines contains the 2 string X and Y.


Output:
For each test case print the length of longest  common substring of the two strings .


Constraints:
1<=T<=200
1<=size(X),size(Y)<=100


Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
************************************************************************************************************************************************************
#include <iostream>
#include<climits>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    int res[n+1][m+1];
	    int gmax = 0;
	    for(int i=0 ; i<n+1; i++){
	        for(int j=0 ; j<m+1 ; j++){
	            if(i==0 || j==0){
	            res[i][j] = 0;
	               continue; 
	            }
	            if(s1[i-1] == s2[j-1]){ 
	            res[i][j] = res[i-1][j-1]+1;
	                gmax = max(gmax , res[i][j]);
	            }
	            else res[i][j] = 0;
	        }
	    }
	    cout<<gmax<<endl;
	    
	}
	return 0;
}
