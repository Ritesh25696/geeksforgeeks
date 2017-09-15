Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3

************************************************************************************************************************************************
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
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int s;
	    cin>>s;
	    vector<vector<int>> res(n+1 ,vector<int>(s+1,0));
	    for(int i=0 ; i<= n ; i++)res[i][0] =1;
	    
	    for(int i=1 ; i<=n ; i++){
	        for(int j=1 ; j<=s ; j++){
	            if(res[i-1][j])res[i][j]+=res[i-1][j];
	            if(A[i-1] <= j){res[i][j]+=res[i-1][j-A[i-1]];}
	        }
	    }
	    
	    cout<<res[n][s]<<endl;
	}
	return 0;
}
