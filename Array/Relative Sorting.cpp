Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2. For the elements not present in A2. Append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
Since 2 is present first in A2[], all occurrences of 2s should appear first in A[], then all occurrences 1s as 1 comes after 2 in A[]. Next all occurrences of 8 and then all occurrences of 3.  Finally we print all those elements of A1[] that are not present in A2[]
 

Input:

The first line of input contains an integer T denoting the number of test cases. The first line of each test case is M and N.  M is the number of elements in A1 and N is the number of elements in A2.
The second line of each test case contains M elements. The third line of each test case contains N elements.

Output:

Print the sorted array according order defined by another array.

Constraints:

1 ≤ T ≤ 50
1 ≤ M ≤ 50
1 ≤ N ≤ 10 & N ≤ M
1 ≤ A1[i], A2[i] ≤ 1000

Example:

Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9
****************************************************************************************************************************
#include<iostream>
#include<vector>
#include<map>

using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n,m;
	    cin>>n>>m;
	    vector<int> A,B;
	    map<int,int>pos;
	    map<int,int>freq;
	    
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	        if(freq.find(p) == freq.end())
	        {
	            freq[p] = 1;
	        }
	        else freq[p]++;
	    }
	    for(int i=0 ; i<m ; i++){
	        int p;
	        cin>>p;
	        pos[i] = p;
	    }
	   
	    for(int i=0 ; i<n && !pos.empty(); i++){
	    int id = pos.begin()->first;
	    int val = pos.begin()->second;
	    pos.erase(pos.begin());
	    if(freq.find(val) != freq.end()){
	        for(int i=0 ; i<freq[val] ; i++){
	            B.push_back(val);
	        }
	          freq.erase(val);
	    }
	    }
	    
	    for(auto i=freq.begin() ; i!=freq.end() ; i++){
            for(int j=0 ; j< i->second ; j++) B.push_back(i->first);
	    }
	    
	    for(int i=0 ; i<B.size() ; i++){
	        cout<<B[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
