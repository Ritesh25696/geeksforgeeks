Write a program to sort an array of 0's,1's and 2's in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, First line is number of elements in array 'N' and second its values.

Output: 
Print the sorted array of 0's, 1's and 2's.

Constraints: 

1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 2

Example:

Input :

2
5
0 2 1 2 0
3
0 1 0
 

Output:

0 0 1 2 2
0 0 1

**************************************************************************************************************
#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t; k++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int i=0, j=A.size()-1,l=0;
	    while(l<=j){
	        if(A[l] == 0){
              A[l] = A[i];
              A[i] = 0;
              i++;l++;
	        }
	        else if(A[l]== 2){
	            A[l] = A[j];
	            A[j] = 2;
	            j--;
	        }
	        else if(A[l] == 1)l++;
	    }
	    for(int i=0 ; i<A.size() ; i++)cout<<A[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
