Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 
Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
-100 ≤ A[i] <= 100
 
Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4
Output
6
-1

**For More Examples Use Expected Output**
***********************************************************************************************************
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n;
	    cin>>n;
	    vector<int>A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int st = 0;
	    vector<int>B(n,INT_MIN);
	    int gmax = A[0];
	    while(A[st] < 0 && st < n){
	        B[st] = 0;
	        if(A[st] >gmax)gmax = A[st];
	        st++;
	    }
        if(st<n){B[st] = A[st]; gmax = A[st];}
        
	    for(int i=st+1 ; i<n ; i++){
	        if(B[i-1] + A[i] < 0)B[i] = 0;
	        else B[i] = B[i-1]+A[i];
	        if(B[i] > gmax && B[i] != 0)gmax = B[i];
	        if(A[i] > gmax )gmax = A[i];
	    }
	    cout<<gmax<<endl;
	}
	return 0;
}
