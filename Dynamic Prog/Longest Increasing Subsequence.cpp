Longest Increasing Subsequence
**********************************************************************************8
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j=0 ; j<t ; j++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int k;
	        cin>>k;
	        A.push_back(k);
	   }
	   int gmax = 0 ; 
	   vector<int> B(n , 1);
	   for(int i=1 ; i<n ; i++){
	       for(int k=0 ; k<i ; k++){
	           if(A[k] < A[i]){
	               B[i] = max(B[i] , B[k]+1);
	           }
	           if(B[i] > gmax)gmax = B[i];
	       }
	   }
	   cout<<gmax<<endl;
	}
	return 0;
}
