Given N, the number of plots on either sides of the road. Find the total ways to construct buildings in the plots such that there is a space between any 2 buildings. All plots on one side of the road are continuous.
Lets suppose ‘*’ represents a plot, then for N=3, the plots can be represented as * * * | | * * *                               

Where | | represents the road.                                                                                                                                                                  
Note: As the answer can be very large, print it mod 1000000007

Input:
First line of input contains T denoting number of test cases. Only line of each test case contains one integers N, as described above.

Output:
For each test case output a single line containing one integer, the answer to the above problem.

Constraints:
1<= T <= 100000
1<= N <= 105

Example:
Input:
1
3

Output:
25

Explanation:
3 plots, which means possible ways for one side are BSS, BSB, SSS, SBS, SSB where B represents a building and S represents an empty space

Total possible ways are 25, because a way to place on one side can correspond to any of 5 ways on other side.
**********************************************************************************************************************************************************

#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;
long long int a,b,c,d;
void fastfib(int n , vector<long long int>& ans){
  if(n == 0){
      ans[0] = 0;
      ans[1] = 1;
      return;
  }
  fastfib(n/2,ans);
   a = ans[0];
   b = ans[1];
   c = 2*b-a;
  if(c<0)c+=MOD;
  c = (a*c)%MOD;
   d = (a*a + b*b)%MOD;
  if(n%2 == 0){
      ans[0] = c;
      ans[1] = d;
  }
  else{
      ans[0] = d;
      ans[1] = c+d;
  }
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<long long int> ans(2);
	    fastfib(n+2,ans);
	    cout<<(ans[0]*ans[0])%MOD<<endl;
	}
	return 0;
}
