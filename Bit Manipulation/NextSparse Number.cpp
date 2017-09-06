Find Next Sparse Number
A number is Sparse if there are no two adjacent 1s in its binary representation. For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
Given a number x, find the smallest Sparse number which greater than or equal to x.

Examples:

Input: x = 6
Output: Next Sparse Number is 8

Input: x = 4
Output: Next Sparse Number is 4

Input: x = 38
Output: Next Sparse Number is 40

Input: x = 44
Output: Next Sparse Number is 64

***************************************************************************************************
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
	    while(n > 0){
	        A.push_back(n&1);
	        n>>=1;
	    }
	    A.push_back(0);
	    int lf = 0;
	    for(int i=1 ; i<A.size()-1 ; i++){
	        if(A[i] == 1 && A[i-1] == 1 && A[i+1] != 1){
	            A[i+1] = 1;
	            for(int j=i ;j >= lf ; j--)
	            A[j] = 0;
	            lf = i+1;
	        }
	    }
	    int ans = 0;
	    for(int i=0 ; i<A.size() ; i++){
	        ans += A[i]*(1<<i);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
