Derek is forming palindromic strings of length lesser than or equal to N, with first K characters of lowercase English language, such that each character in a string doesn’t appear more than twice.

Help Derek in finding out the total number of such strings formed.

 

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two integers N and K as described in the problem statement.
 

Output:

For each test case, print in a new line, the number of such strings formed. As the results can be very large, print your answer modulo 10^9+7.

 

Constraints:

1 <= T <= 100

1 <= K <= 26

1 <= N <= 52

2*K >= N

 

Example:

Input:

2

3 2

4 3

Output:

6

18

Explanation:

For the 1st sample test case:

The possible strings are: “a”, “b”, “aa”, “bb”, “aba”, “bab”. Hence, the answer is 6.

For the 2nd sample test case:

The possible strings are: "a", "b", "c", "aa", "bb", "cc", "aba", "aca", "bab", "bcb", "cac", "cbc", "abba", "acca", "baab", "bccb", "caac", "cbbc". Hence, the answer is 18.

********************************************************************************************************************************************
#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;cin>>t;
	while(t--)
	{
	    long long k,n;cin>>n>>k;
	    long long temp,i,ans=0,a1,j,m=1000000007;
	    for(i=1;i<=n;i++)
	    {
	        temp=(i+1)/2;
	        
	        for(a1=1,j=k;temp >=1;temp--)
	        {
	            a1*=j;
	            j--;
	            a1=a1%m;
	            if(temp==1)
	              {  ans=(ans+a1)%m;
	              }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
