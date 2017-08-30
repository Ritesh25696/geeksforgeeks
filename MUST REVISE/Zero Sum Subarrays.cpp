Given an array of size N , print the total count of sub-arrays having their sum equal to 0

Input: First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array and the second line contains N space separated integers.

Output: Corresponding to each test case, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1<= N <= 10000
-100 <= A[i] <= 100 where i <= N

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4
***************************************************************************************************************
somewhat similar to finading maximum subarray with sum 0
***************************************************************************************************************

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    int count = 0;
	    unordered_map<int, int> mymap;
	    for(int j=0 ; j<n ; j++){
	        int k;
	        cin>>k;
	        if(A.size() == 0)
	        A.push_back(k);
	        else A.push_back(A[j-1] + k);
	        if(A[j] == 0)count++;
	        if(mymap.find(A[j]) == mymap.end())mymap[A[j]] = 1;
	        else{
	            count+=mymap[A[j]];
	            mymap[A[j]]++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
