As we know that every number >=2 can be represented as natural powers of primes(prime factorization). Also prime factorization is unique for a number. 

Eg. 360 = 233251

Today we are interested in geek numbers. A geek number is a number whose prime factorization only contains powers of unity.Below are some geek numbers.

Eg. 2 = 21
    22 = 21111

Input: 

First line of the input file contains an integer T which denotes the number of test cases. Then T test cases follow. First line of each test case contains a number N.


Output: 

For each test case, print "Yes"(without quotes) if it is a geek number, else print "No"(without quotes).


Constraints:
1<=T<=10000
2<=N<=106
Example:
Input:
2
22
360

Output:
Yes
No
*************************************************************************************************
#include <bits/stdc++.h>
using namespace std;

bool ans(int n){
    int c=0;
    while(n%2 == 0){
        n/=2;
        c++;
    }
    if(c>1)
    return false;
    c=0;
    for(int i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            n/=i;
            c++;
        }
        if(c>1)
        return false;
        c=0;
    }
    if(n>2)
    return true;
}

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    if(ans(n))
	    cout<<"Yes";
	    else
	    cout<<"No";
	    cout<<endl;
	}
	return 0;
}
