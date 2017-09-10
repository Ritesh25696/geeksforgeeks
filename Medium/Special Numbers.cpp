A number is a special number if it’s digits only consist 0, 1, 2, 3, 4 or 5.

Given a number n and we have to find n-th Special Number. 

Input:
First line of input contains the number of test cases.

The only line of the test case contains N.

Output:

Print the nth special number.

Constraints:

1<=T<=100

1<=N<=100000


Example:

Sample Input:

2
6
10

Sample Output:

5
13
********************************************************************************************************************************
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<6 ; i++){
	        A.push_back(i);
	    }
	    for(int i=1 ; i<=n ; i++){
	        for(int j=0 ; j<6 ; j++){
	            A.push_back(10*A[i]+A[j]);
	        }
	    }
	    cout<<A[n-1]<<endl;
	}
	return 0;
}
