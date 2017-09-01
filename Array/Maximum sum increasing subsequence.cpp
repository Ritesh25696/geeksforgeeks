Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[].

Output:

Print the sum of maximum sum sequence of the given array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ A[] ≤ 1000

Example:

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
For input:
7
1 101 2 3 100 4 5
All the increasing subsequences : (1,101); (1,2,3,100); (1,2,3,4,5), out of this (1,2,3,100) has maximum sum,i.e., 106. Hence the output is stated as 106.
&**********************************************************************************************************************
#include<vector>
#include<climits>
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int z=0 ; z<t ; z++){
	    int n ;
	    cin>>n;
	    vector<int> A;
	    vector<int> B;
	    for(int i=0 ; i<n; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	        B.push_back(p);
	    }
	    
	    int gmax = A[0];
	    for(int i=1 ; i<A.size() ; i++){
	        for(int j=0 ; j<i ; j++){
	            if(A[j] < A[i]){
	                B[i] = max(B[i],B[j]+A[i]);
	                if(B[i]>gmax)gmax = B[i];
	            }
	        }
	    }
	    cout<<gmax<<endl;
	}
	return 0;
}
