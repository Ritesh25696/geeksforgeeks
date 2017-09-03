Given an array of integers, sort the array according to frequency of elements. For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. 

If frequencies of two elements are same, print them in increasing order.

 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:

Print each sorted array in a seperate line. For each array its numbers should be seperated by space.


Constraints:

1 ≤ T ≤ 70
30 ≤ N ≤ 130
1 ≤ A [ i ] ≤ 60 


Example:

Input:

1
5
5 5 4 6 4

Output:

4 4 5 5 6 

**************************************************************************************************************************************************************************************
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>a ,pair<int,int> b){
if(a.first == b.first)return a.second<b.second;
return a.first>b.first;
}

int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t; ct++){
	    int n;
	    cin>>n;
	    map<int,int> freq;
	    vector<pair<int,int>> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        if(freq.find(p) == freq.end())
	           freq[p] = 1;
	        else
	           freq[p]++;
	    }
	    for(auto i=freq.begin() ; i!=freq.end() ; i++){
	        A.push_back(make_pair(i->second,i->first));
	    }
	   // for(int i=0 ; i<A.size() ;i++){
    //         cout<<A[i].first<<" "<<A[i].second<<endl;
	   // }
	    sort(A.begin(),A.end(),comp);
	    for(int i=0 ; i<A.size() ; i++){
	        for(int j=0 ;j<A[i].first ; j++){
	            cout<<A[i].second<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
