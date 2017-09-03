Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer 'N' denoting the size of array and the size of subarray 'k'.
The second line contains 'N' space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 100
1 ≤ k ≤ N
0 ≤A[i]<1000

Example:

Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90
*************************************************************************************************************************************

#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct = 0 ; ct<t ; ct++){
	    int n, k;
	    cin>>n>>k;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int maxi = INT_MIN , max= INT_MIN;
	    for(int i=0 ; i<=n ; i++){
	        if(i>=k){
	            cout<<max<<" ";
	        }
	        if(maxi == i-k){maxi = INT_MIN;max = INT_MIN;
	            for(int j= i-k+1 ; j<i ; j++)
	            if(A[j] > max){
	                maxi = j;
	                max = A[j];
	            }
	        }
	        if(i<n && A[i]>max){max = A[i];maxi = i;}
	    }
	    cout<<endl;
	}
	return 0;
}
