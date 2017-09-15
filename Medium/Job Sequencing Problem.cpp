Given a set of n jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input:
The first line of input contains an integer T denoting the number of test cases.Each test case consist of an integer N denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.

Output:
Output the number of jobs done and the maximum profit.

Constraints:
1<=T<=100
1<=N<=100
1<=Deadline<=100
1<=Profit<=500

Example:
Input:
2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15
Output:
2 60
2 127

*************************************************************************************************************************************************************************************************************************************88

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>a ,pair<int, int> b ){
    return a.first>b.first;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int>> A;
	    for(int i=0 ; i<n ; i++){
	        int a,b,c;
	        cin>>a>>b>>c;
	        A.push_back(make_pair(c , b));
	    }
	    sort(A.begin(),A.end(),comp);
	    vector<bool> slot(n+1, false);
	    int count =0;
	    int value = 0;
	    for(int i=0 ; i<A.size() ; i++){
	        for(int j = min(n,A[i].second); j>=1 ; j--){
	            if(!slot[j]){
	                slot[j] = true;
	                value += A[i].first;
	                count++;
	                break;
	            }
	        }
	    }
	    cout<<count<<" "<<value<<endl;
	}
	return 0;
}
