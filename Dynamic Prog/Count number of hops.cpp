Frog steps either 1, 2 or 3 steps to go to top. In how many ways it reaches the top?

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N. Where is the number of steps it has to hop.

Output:

Print the number of ways.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 50

Example:

Input:
2
1
5

Output:
1
13
**************************************************************************************************************************************
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n;
	    cin>>n;
	    vector<int> res(n,1);
	    res[0] = 1;
	    res[1] = 2;
	    res[2] = 4;
	    for(int i=3 ; i<n ; i++){
	        res[i] = res[i-1]+res[i-2]+res[i-3];
	    }
	    cout<<res[n-1]<<endl;
	}
	return 0;
}
