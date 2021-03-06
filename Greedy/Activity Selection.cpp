Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.
 
Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.
 

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100
 

Example:
Input:
1
6
1 3 0 5 8 5
2 4 6 7 9 9

Output:
4

**********************************************************************************************************
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int>a , pair<int, int> b){
    return a.second<b.second;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int>> A(n);
	    for(int i=0 ; i<n ; i++){
	        cin>>A[i].first;
	    }
	    for(int i=0 ; i<n ; i++){
	        cin>>A[i].second;
	    }
	    sort(A.begin(),A.end(),comp);
	    int count = 1;
	    int end = A[0].second;
	    for(int i=1; i<A.size() ; i++){
	        if(A[i].first >= end){
	            count++;
	            end = A[i].second;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
