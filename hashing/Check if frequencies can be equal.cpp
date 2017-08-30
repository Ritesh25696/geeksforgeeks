Given a string s which contains lower alphabetic characters, the task is to check if its possible to  remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string.
Examples:

Input  : s = “xyyz”
Output : 1
We can remove character ’y’ from above 
string to make the frequency of each 
character same. 

Input : s = “xxxxyyzz” 
Output : 0
It is not possible to make frequency of 
each character same just by removing at 
most one character from above string.

**************************************************************************************************************************88

#include<iostream>
#include<unordered_map>
#include<climits>
#include<map>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int j=0 ; j<t ; j++){
	    string s;
	    cin>>s;
	    unordered_map<int, int >mymap;
	    for(int i=0 ; i<s.length() ; i++){
	        if(mymap.find(s[i]) == mymap.end())mymap[s[i]] = 1;
	        else mymap[s[i]]++;
	    }
	    map<int,int> temp;
	    for(auto i = mymap.begin() ; i!= mymap.end() ; i++){
	        int l = i->first;
	        int m = i->second;
	        if(temp.find(m) == temp.end())temp[m] = 1;
	        else temp[m]++;
	    }
	    bool done = false;
	    if(temp.size() > 2){cout<<0<<endl;done = true;}
	    if(temp.size() == 1){cout<<1<<endl; done = true;}
	    if(!done){
	        int z = temp.begin()->second , y = temp.begin()->first;
	        if(y == 1 && z == 1){cout<<1<<endl;done = true;}
	        else{temp.erase(y);
            int q = temp.begin()->second, w = temp.begin()->first;
            if(w == y+1 && q == 1){cout<<1<<endl; done = true;}}
	    }
	    if(!done)cout<<0<<endl;
	}
	return 0;
}
