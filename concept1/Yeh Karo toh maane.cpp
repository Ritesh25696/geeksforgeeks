Saksham has recently learnt about Fibonacci series, and told his father about it. His father being a mathematician asked him to tell the Nth number of the Fibonacci series.
But, Saksham told his father that it is difficult to solve the series as he is getting very large numbers. His father being lenient made his work less and asked to tell only last two digits of the Nth number of Fibonacci series. Please help Saksham to find the answer.


Note: 1st element of series is 1. And 2nd element of series is 1.
If last 2 digits are 03(for instance) print 3.

Input:
First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an integer N.

Output:
Corresponding to each test case, print the required output in a new line.

Constraints:
1<=T<=100
1<=N<=10^9

Example:
Input:
8
1
2
3
4
5
6
7
8
Output:
1
1
2
3
5
8
13
21

***********************************************************************************

#include<bits/stdc++.h>

using namespace std;

int a, b, c , d;
void fast_fib(int n, vector<int>& ans){

    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
       c+=100;
    c = (a * c);      /* F(2n) */
    d = (a*a + b*b);  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c%100;
        ans[1] = d%100;
    }
    else
    {
        ans[0] = d%100;
        ans[1] = (c+d)%100;
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> ans(2);
	    fast_fib(n, ans);
	    cout<<ans[0]<<endl;
	}
	return 0;
}
