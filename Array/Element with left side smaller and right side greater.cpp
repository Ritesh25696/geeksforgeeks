Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1<=T<=100
3<=N<=106
1<=A[i]<=106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7

****************************************************************************************************************************************************************************************
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p ;
	        A.push_back(p);
	    }
        vector<int> right(n,0);
        vector<int> left(n,0);
        int max = INT_MIN;
        bool done = false;
        for(int i=0 ; i<n ; i++){
         if(A[i] > max)
         max = A[i];
         right[i] = max;
        }
        int min = INT_MAX;
        for(int i=A.size()-1 ; i>=0 ; i--){
            if(A[i]<min)
            min = A[i];
            left[i] = min;
        }
        for(int i=1 ; i<A.size()-1 ; i++){
            if(right[i] == left[i]){
                cout<<A[i]<<endl;
                done = true;
                break;
            }
        }
        if(!done)cout<<-1<<endl;
	}
	return 0;
}
