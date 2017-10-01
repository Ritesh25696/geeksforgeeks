A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)

Input:

The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array.
The second line of each test case contains N space separated integers denoting array elements.

Output:
Corresponding to each test case, in a new line, print the minimum element in the array.

Constraints:

1 ≤ T ≤ 200
1 ≤ N ≤ 500
1 ≤ A[i] ≤ 1000

Example:

Input
1
5
4 5 1 2 3

Output
1

************************************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;

int findp(vector<int>A){
    int low = 0 , high = A.size()-1;
    int n = A.size();
    while(low<=high){
        //cout<<"low "<<low<<" high "<<high<<endl; 
        if(A[low] < A[high])return low;
        int mid = (low+high)/2;
        //cout<<"mid"<<mid<<endl;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[mid]<= A[next] && A[mid] <= A[prev])return mid;
        
        if(A[mid]>=A[low])low = mid+1;
        else if(A[mid] <= A[high]) high = mid-1;
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> A(n);
	    for(int i=0 ; i<n ; i++){
	        cin>>A[i];
	    }
	    int piv = findp(A);
	    cout<<A[piv]<<endl;
	}
	return 0;
}
