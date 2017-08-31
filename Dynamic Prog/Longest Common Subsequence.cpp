#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    int res[n+1][m+1];
	    for(int i=0 ; i<=n ; i++) res[i][0] = 0;
	    for(int i=0 ; i<=m ; i++) res[0][i] = 0;
	    for(int i=1 ; i<= n ; i++){
	        for(int j=1 ; j<=m ; j++){
	            if(a[i-1] == b[j-1])
	            res[i][j] = res[i-1][j-1]+1;
	            else{
	                res[i][j] = max(res[i-1][j], res[i][j-1] );
	            }
	        }
	    }
	    cout<<res[n][m]<<endl;
	}
	return 0;
}
