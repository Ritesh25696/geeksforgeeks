Find the sum of all bits from numbers 1 to N.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.

Output:

Print the sum of all bits.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 1000

Example:

Input:
2
4
17

Output:
5
35

Explanation:
An easy way to look at it is to consider the number 6:
0|0 0
0|0 1
0|1 0
0|1 1
-|–
1|0 0
1|0 1
1|1 0
************************************************************************************************************************************************************
#include<iostream>
using namespace std;
int countbit(int n){
    if(n == 0)return 0;
    return (n%2 == 0? 0:1) + countbit(n/2);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int res = 0;
	    for(int i=1 ; i<=n ; i++){
	        res+=countbit(i);
	    }
	    cout<<res<<endl;
	}
	return 0;
}
