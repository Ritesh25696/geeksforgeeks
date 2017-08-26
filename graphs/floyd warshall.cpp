The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are V*V space separated values of the matrix (graph) .

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex.

Constraints:
1<=T<=20 
1<=V<=20
-1000<=graph[][]<=1000

Example:
Input
2
2
0 25 25 0
3
0 1 43 1 0 6 43 6 0

Output
0 25 25 0 
0 1 7 1 0 6 7 6 0 

************************************************************************************************************************************
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    int n;
	    cin>>n;
	    int k;
	    int g[n][n];
	    for(int i=0 ;i<n; i++){
	        for(int j=0 ; j<n ; j++){
	            cin>>k;
	            g[i][j] = k;
	        }
	    }
	    
	    int res[n][n];
	    for(int i=0 ;i<n; i++){
	        for(int j=0 ; j<n ; j++){
	            res[i][j] = g[i][j];
	        }
	    }
	    for(int k=0 ; k<n ; k++){
	        for(int i=0 ; i<n ; i++){
	            for(int j=0 ; j<n ; j++){
	                if(res[i][j] > res[i][k]+res[k][j])
	                res[i][j] = res[i][k]+res[k][j];
	            }
	        }
	    }
	    for(int i=0 ;i<n; i++){
	        for(int j=0 ; j<n ; j++){
	            cout<<res[i][j]<<" ";
	        }
	    }cout<<endl;
	}
	return 0;
}
