Given an array of n integers. The task is to find the first element that occurs k number of times. If no element occurs k times the print -1. The distribution of integer elements could be in any range.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of an array and the number K. The second line of each test case contains N space separated integers denoting elements of the array A[ ].

Output:
For each test case in a new line print the required answer.


Constraints:
1<= T <=100
1<= N,K <=100000
1<= A<=1000000


Example:

Input :
1
7 2
1 7 4 3 4 8 7

Output :
7

Explanation:
Both 7 and 4 occur 2 times. But 7 is the first that occurs 2 times.

**For More Examples Use Expected Output**
**************************************************************************************************************************************************8

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j=0 ; j<t ; j++){
	    int n, p;
	    cin>>n>>p;
	    unordered_map<int,int> mymap;
	    bool done = false;
	    vector<int> B;
	    for(int i=0 ; i<n ; i++){
	        int k;
	        cin>>k;
	        B.push_back(k);
	        if(mymap.find(k) == mymap.end()){
	            mymap[k] = 1;
	        }
	        else mymap[k]++;
	    }
	    for(int i=0 ; i<n ; i++){
	        if(mymap[B[i]] == p){
	            cout<<B[i]<<endl;
	            done = true;
	            break;
	        }
	    }
	    if(!done)cout<<-1<<endl;
	}
	return 0;
}
