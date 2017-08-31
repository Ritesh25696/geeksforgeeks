Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

Input:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the order of matrix. Next line contains N*N integers denoting the elements of the matrix in row-major form.

Output:
Output the largest sum of any of the paths starting from any cell of row 0 to any cell of row N-1. Print the output of each test case in a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 (for all 1<=i<=N && 1<=j<=N)

Example:

Input:
1
2
348 391 618 193

Output:
1009

Explanation: In the sample test case, the path leading to maximum possible sum is 391->618.  (391 + 618 = 1009)
**************************************************************************************************************************************************88
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k= 0; k<t ; k++){
	    int n;
	    cin>>n;
	    int in[n][n];
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ;j<n ; j++){
	            int p;
	            cin>>p;
	            in[i][j] = p;
	        }
	    }
	    int res[n][n+2];
	    for(int i=0 ; i<n ; i++){
	        res[i][0] = 0;
	        res[i][n+1] = 0;
	    }
	    for(int i=1 ; i<n+1 ; i++){
            res[0][i] = in[0][i-1];
	    }
	    int gmax=0;
	    for(int i=1 ; i<n ; i++){
	        for(int j = 1 ; j<=n ; j++){
	            res[i][j] = max(res[i-1][j],max(res[i-1][j-1],res[i-1][j+1]))+in[i][j-1];
	            if(res[i][j] > gmax)gmax = res[i][j];
	        }
	    }
	    cout<<gmax<<endl;
	}
	return 0;
}
