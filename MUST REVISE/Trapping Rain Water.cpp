Given n non-negative integers in array representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example:
Input:
3
2 0 2
Output:
2
Structure is like below
|  |
|_|
We can trap 2 units of water in the middle gap.

Below is another example.



Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains an integer N followed by N numbers to be stored in array.

Output:
Print trap units of water in the middle gap.

Constraints:
1<=T<=100
3<=N<=100
0<=Arr[i]<10

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
 0
 
**********************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    vector<int> hright(A.size() , 0);
	    int hleft = 0 , maxh = 0 , rw=0;
	    for(int i=A.size()-1 ; i>=0 ; i--){
	        if(A[i] > maxh){
	            maxh = A[i];
	            hright[i] = maxh;
	        }
	        else{
	            hright[i] = maxh;
	        }
	    }
	    for(int i=0 ; i<A.size() ; i++){
	        rw += max(min(hleft,hright[i])-A[i],0);
	        if(A[i] > hleft)
	        hleft = A[i];
	    }
	    cout<<rw<<endl;
	}
	return 0;
}
