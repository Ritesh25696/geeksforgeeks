A number n is said to be a Carmichael number if it satisfies the following modular arithmetic condition:

  power(b, n-1) MOD n = 1, 
  for all b ranging from 1 to n such that b and 
  n are relatively prime, i.e, gcd(b, n) = 1 
Given a positive integer n, find if it is a Carmichael number.

Input:

First line of input contains the number of test cases.

Only line of each test case contains the number n.


Output:
Print "Yes" if the number is a Carmichael number else "No" without quotes.

Constraints:

1<=T<=100

1<=N<=100000


Example:

Sample Input:

1
8

Sample Output:
No

Explanation :
8 is not a Carmichael number because 3 is relatively prime to 8 and

(38-1) % 8 = 2187 % 8 is not 1.



******************************************************************************************************

#include <iostream>
using namespace std;

long long modfun(int a, int b, int n){
    int res;
    while(b){
        if(b%2){
            res = (res*a)%n;
        }
        a = (a*a)%n;
        b/=2;
    }
}

int hcf(int a, int b){
    int temp;
    if(b>a)swap(a,b);
    while(1){
        temp = a%b;
        if(temp == 0)return b;
        a = b;
        b = temp;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    bool done = false;
	    for(int i=2 ; i<n; i++){
	        if(hcf(n,i)>1){
	            if(modfun(i,n-1,n) != 1){
	                cout<<"No"<<endl;
	                done = true;
	                break;
	            }
	        }
	    }
	    if(!done)cout<<"Yes"<<endl;
	}
	return 0;
}
