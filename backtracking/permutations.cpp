#include<iostream>
#include<vector>
using namespace std;

void printall(string s , string r, vector<bool>&vis ){
    if(r.length() == s.length()){
        cout<<r<<" ";
        return;}
    for(int i=0 ; i<s.length() ; i++){
        if(!vis[i]){
         vis[i] = true;
        printall(s , r+s[i], vis);
        vis[i] = false;
        }
    }return;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    vector<bool> temp(s.length(), false);
	    printall(s ,"", temp );
	    cout<<endl;
	}
	return 0;
}
