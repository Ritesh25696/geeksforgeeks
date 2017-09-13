We are given a row wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next r line contains space separated c elements each in the array a[].​

Output:
Print an integer which is the median of the matrix.

Constraints:
1<= T <=100
1<= r,c <=150
1<= a[i][j] <=1000

Example:
Input:
1
3 3
1 3 5
2 6 9
3 6 9

Output:
5
************************************************************************************************************
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int median(vector<vector<int>> &A , int mini , int maxi){
    int des = (A.size()*A[0].size())/2+1;
    while(mini<maxi){
        int mid = mini + (maxi-mini)/2;
        int place = 0;
        for(int i=0 ; i<A.size(); i++)
            place += upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        if(place < des)mini = mid+1;
        else maxi = mid;
    }
    return mini;
}

int main()
 {
	int t=0;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> A(n , vector<int>(m));
	    int mini = INT_MAX;
	    int maxi = INT_MIN;
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            cin>>A[i][j];
	            mini = min(mini,A[i][j]);
	            maxi = max(maxi,A[i][j]);
	        }
	    }
	    cout<<median(A,mini,maxi)<<endl;
	}
	return 0;
}
