In a town , the Chief Council of Ministers has decided to contribute funds raised from various sources in their department for the Central Public Welfare Initiatives. Given the contribution of N ministers Ai, where i represents the contribution of the ith minister, what should be the least contribution from the chief such that the Nth power of his share is atleast equal to the product of contributions of all his subordinates.

Input: 
First line of input contains the number of test cases , T. First line of each test case contains the number of ministers,N . Second line of each test case contains n space seperated values (A1 TO An) denoting the contribution of N ministers.

Output:
For each test case , output a single integer denoting the minimum contribution by the chief.

Constraints:

1<=T<=100
1<=N<=1000
1<=Ai<=100

Example:
Input:
1
5
3 4 2 1 5
Output: 
3
******************************************************************************************************************************************

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    float sum =0;
	    for(int i=0 ; i<n ; i++){
	        float p;
	        cin>>p;
	        sum+=log(p);
	    }
	    bool  done = false;
	    for(int i=1 ; i<1000 ; i++){
	        if(n*log(i) >= sum){
	            cout<<i<<endl;
	            done = true;
	            break;
	        }
	    }
	    if(!done)cout<<1<<endl;
	}
	return 0;
}
