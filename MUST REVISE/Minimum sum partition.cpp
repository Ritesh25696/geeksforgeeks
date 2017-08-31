Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11
***************************************************************************************************
#include<iostream>
#include<vector>
using namespace std;

int check(vector<int>&A , int s){
    int n = A.size();
    bool res[n+1][s+1];
    for(int i=0 ; i<=s ; i++)res[0][i] = false;
    for(int i=0 ; i<=n ; i++)res[i][0] = true;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=s ; j++){
            res[i][j]= res[i-1][j];
            if(A[i-1]<=j)
            res[i][j] |= res[i-1][j-A[i-1]];
        }
    }
    
    for(int i=s ; i>=0 ; i--){
     if(res[n][i])return i;  
    }
}

int main()
 {
	int t;
	cin>>t;
	for(int k=0 ;k<t ; k++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    int sum =0;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	        sum+=p;
	    }
	    cout<<sum-(2*check(A,sum/2))<<endl;
	}
	return 0;
}
