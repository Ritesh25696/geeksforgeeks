Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
Constraints: 

1 <= T<= 100
1 <= N<= 100
0 <= arr[i]<= 1000

                   
Example:

Input:
2
4
1 5 11 5
3
1 3 5 

Output:

YES
NO
************************************************************************************************************
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSubsetSum(vector<int> &set, int n, int sum)
{
   bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
  
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;
  
      for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]];
       }
     }
     return subset[n][sum];
}

int main()
 {
	int t;
	cin>>t;
	for(int k=0 ; k<t ; k++){
	    int n;
	    cin>>n;
	    int s = 0;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	        s+=p;
	    }
	    bool done = false;
	    if(s %2 != 0){
	        cout<<"NO"<<endl;
	        done = true;
	    }
	    s/=2;
	   if(!done && isSubsetSum(A , A.size() , s)){cout<<"YES"<<endl;done = true;}
	   if(!done)cout<<"NO"<<endl;
	}
	return 0;
}
