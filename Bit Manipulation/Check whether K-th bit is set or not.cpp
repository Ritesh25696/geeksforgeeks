#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n , k;
	    cin>>n>>k;
	    n>>=k;
	    if(n&1)cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}
