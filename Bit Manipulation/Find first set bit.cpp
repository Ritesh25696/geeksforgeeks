#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int num;
	    cin>>num;
	    int count =1;
	    while(num > 0 ){
	        if(num & 1){
	        cout<<count<<endl;
	        break; 
	        }
	        count++;
	        num>>=1;
	    }
	    if(num == 0)cout<<0<<endl;
	}
	return 0;
}
