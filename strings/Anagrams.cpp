Given two strings, check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input:

The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a separate line.

Output:

Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:

1 ≤ T ≤ 30

1 ≤ |s| ≤ 100

Example:

Input:
2
geeksforgeeks
forgeeksgeeks
allergy
allergic

Output:
YES
NO
*******************************************************************************************

#include<iostream>
#include<unordered_map>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct = 0 ; ct<t ; ct++){
	    string s1,s2;
	    cin>>s1>>s2;
	    bool done = false;
	    if(s1.length() != s2.length()){
	        cout<<"NO"<<endl;
	        done = true;
	    }
	    if(!done){
	        int n = s1.length();
	        unordered_map<char, int> mymap;

	        for(int i=0 ; i<n ; i++){
	            if(mymap.find(s1[i]) == mymap.end())mymap[s1[i]] = 1;
	            else mymap[s1[i]]++;
	        }

	        for(int i=0 ; i<n ; i++){
	            if(mymap.find(s2[i]) == mymap.end()){
	                cout<<"NO"<<endl;
	                done = true;
	                break;
	            }
	            else {mymap[s2[i]]--;
	            if(mymap[s2[i]]  == 0)mymap.erase(s2[i]);}
	        }
	        if(!done)cout<<"YES"<<endl;
	    }
	}
	return 0;
}
