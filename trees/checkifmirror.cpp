Given two n-ary tree's the task is to check if they are mirror of each other or not.

Example

     1                    1
   /    \                 /   \
 2      3             3     2

Output: 1

    1                      1
   /  \                    /  \
 2    3                2    3

Output: 0

Note: you may assume that root of both the given tree as 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two space separated values n and e denoting the no of nodes and edges respectively. Then in the next line two lines are 2*e space separated values u,v denoting an edge from u to v for the both trees .

Output:
For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

Constraints:
1<=T<=20
1<=n<=15
1<=e<=20

Example:
Input:
2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3
Output:
1
0

***************************************************************************************************************************
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool mirror(vector<stack<int>> &st , vector<queue<int>> &q){
    for(int i=1 ; i < st.size() ; i++){
    stack<int> x = st[i];
    queue<int> y = q[i];
    while(!x.empty() && !y.empty()){
        if(x.top() == y.front()){
            x.pop();
            y.pop();
        }
        else return false;
    }
        if(!x.empty() || !y.empty())return false;
    }return true;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<int> u1 , u2, v1,v2;
	    for(int i=0 ; i<2*e ; i++){
	        int p;
	        cin>>p;
	        if(i%2 == 0)
	            u1.push_back(p);
	        else 
	            v1.push_back(p);
	    }
	    for(int i=0 ; i<2*e ; i++){
	        int p;
	        cin>>p;
	        if(i%2 == 0)
	        u2.push_back(p);
	        else v2.push_back(p);
	    }
	 
	    vector<stack<int>> st(v+1);
	    vector<queue<int>> q(v+1);
	    for(int i=0 ; i<u1.size() ; i++){
	        st[u1[i]].push(v1[i]);
	        q[u2[i]].push(v2[i]);
	    }
	    if(mirror(st , q))cout<<1<<endl;
	    else cout<<0<<endl;
	}
	return 0;
}
