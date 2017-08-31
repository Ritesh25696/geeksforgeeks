The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
In this problem you have to find minimum trials to solve for n eggs and k floors.
For more description on this problem see wiki page

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains 2 integers n and k.


Output:
Print the minimum trials required to solve the problem.
 

Constraints:
1<=T<=30
1<=n<=10
1<=k<=50


Example:
Input:
1
2 10

Output:
4
************************************************************************************************
#include<iostream>
#include<climits>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int z=0 ; z<t ; z++){
	    int n,k;
	    cin>>n>>k;
	    int res[n+1][k+1];
	    for(int i=0 ; i<=n ; i++){
	        res[i][0] = 0 ;
	        res[i][1] = 1 ;
	    }
	    for(int i=1 ; i<=k ; i++){
	        res[1][i] = i;
	    }
	    for(int i =2; i<= n ; i++){
            for(int j=2 ; j<=k ; j++){
                res[i][j] = INT_MAX;
                for(int x=1 ; x<=j ; x++){
                    int eggs = 1+max(res[i-1][x-1],res[i][j-x]);
                    if(eggs < res[i][j])
                    res[i][j] = eggs;
                }
            }
	    }
	    cout<<res[n][k]<<endl;
	}
	return 0;
}
