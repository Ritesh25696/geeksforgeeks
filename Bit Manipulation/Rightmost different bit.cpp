Given two numbers M and N. Write a program to find the position of rightmost different bit in binary representation of numbers.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers M and N.

Output:
For each test case print the position of rightmost different bit in binary representation of numbers. If both M and N are same then print -1 in this case.

Constraints:
1<=T<=100
1<=M<=1000
1<=N<=1000

Example:
Input:
2
11 9
52 4
Output:
2
5
*************************************************************************************************************
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    int count = 1;
	    bool  done =  false;
	    while(n>0 || m>0){
	        int k = n&1;
	        int l = m&1;
	        if(k != l){
	            cout<<count<<endl;
	            done = true;
	            break;
	        }
	        count++;
	        n>>=1;
	        m>>=1;
	    }
	    if(!done)cout<<-1<<endl;
	}
	return 0;
}
