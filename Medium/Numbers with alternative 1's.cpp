Given a number n, the task is to find all 1 to n bit numbers with no consecutive 1's in their binary representation.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n.

Output:
Print all those numbers in new line.

Constraints:
1<=T<=20
1<=n<=20

Example:
Input:
2
3
4

Output:
1 2 4 5
1 2 4 5 8 9 10
***********************************************************************************************************************************
#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

set<int> myset;

void util(vector<int> sol , int n){
    if(sol.size()<=n){
        int j=0 , ans = 0;
        for(int i=sol.size()-1 ; i>=0 ; i--){
            if(sol[i])ans+=pow(2,j);
            j++;
        }
    myset.insert(ans);
    int ld = sol[sol.size()-1];
    if(ld == 1){
        sol.push_back(0);
        util(sol , n);
    }
    else{
        sol.push_back(1);
        util(sol,n);
        sol.erase(sol.begin()+sol.size()-1);
        sol.push_back(0);
        util(sol,n);
    }
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> sol;
	    sol.push_back(1);
	    util(sol,n);
	    for(auto i=myset.begin() ; i!=myset.end() ; i++){
	        cout<<*i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
