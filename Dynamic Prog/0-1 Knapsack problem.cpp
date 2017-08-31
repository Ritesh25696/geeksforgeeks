#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n, w;
	    cin>>n>>w;
	    vector<int> val , wt;
	    for(int i=0 ; i<n ; i++){
	        int k;
	        cin>>k;
	        val.push_back(k);
	    }
	    for(int i=0 ; i<n ; i++){
	        int k;
	        cin>>k;
	        wt.push_back(k);
	    }
	    vector<pair<int,int>> P;
	    for(int i=0 ; i<n ; i++){
	        P.push_back(make_pair(wt[i],val[i]));
	    }
	    sort(P.begin(),P.end());
	    int res[n+1][w+1];
	    for(int i=0 ; i<=n ; i++){
	        for(int j=0 ; j<=w ; j++){
	            if(i==0 || j == 0){
	            res[i][j] = 0;
	                continue;
	            }
	            if(P[i-1].first <= j)
	            res[i][j] = max(res[i-1][j-P[i-1].first]+P[i-1].second, res[i-1][j]);
	            else res[i][j] = res[i-1][j];
	        }
	    }
	    cout<<res[n][w]<<endl;
	}
	return 0;
}
