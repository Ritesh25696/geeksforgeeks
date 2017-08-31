#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n ;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	     vector<int> jumps(n , INT_MAX);
	     jumps[0] = 0;
	     int pmax = 0;
	     bool done = false;
	     for(int i=0 ; i<n ; i++){
	         if(jumps[i] == INT_MAX)continue;
	         if(done == false && A[i]+i > pmax ){
	             for(int j=pmax+1 ; j<=A[i]+i && j<n; j++){
	             jumps[j] = jumps[i]+1;
	             if(j == n-1){
	             cout<<jumps[j]<<endl;
	             done = true;
	             }
	             }
	             pmax = A[i]+i;
	         }
	         if(done){break;}
	     }
	     if(!done)cout<<-1<<endl;
	}
	return 0;
}
