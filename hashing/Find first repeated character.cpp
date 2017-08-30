#include<iostream>
#include<unordered_set>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    string s;
	    cin>>s;
	    unordered_set<char> mymap;
	    bool done = false;
	    for(int i=0 ; i<s.length() ; i++){
	        if(mymap.find(s[i]) != mymap.end()){done = true;cout<<s[i]<<endl;break;}
	        mymap.insert(s[i]);
	    }
	    if(!done)cout<<-1<<endl;
	}
	return 0;
}
