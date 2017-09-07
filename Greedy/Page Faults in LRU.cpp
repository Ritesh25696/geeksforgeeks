In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when new page comes in. Whenever a new page is referred and is not present in memory, page fault occurs and Operating System replaces one of the existing pages with newly needed page.
Given a sequence of pages and memory capacity, your task is to find the number of page faluts using Least Recently Used (LRU) Algorithm .

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains number of pages n and next line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.

Output:
Output the number of page faults.

Constraints:
1<=T<=100
1<=n<=1000
4<=capacity<=100

Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4
Output:
8
7

***************************************************************************************************************************************************


#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    vector<int> A;
	    cin>>n;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int m,count=0;
	    cin>>m;
	    vector<int> memory;
 	    for(int i=0; i<A.size() ; i++){
	        
	        if(memory.size() < m){
	            bool done = false;
	            for(int j=0 ; j<memory.size() ;j++){
	            if(memory[j] == A[i]){
	                memory.erase(memory.begin()+j);
	                memory.push_back(A[i]);
	                done = true;
	                continue;
	            }
	        }
	            if(!done){
	            memory.push_back(A[i]);
	            count++;}
	            continue;
	        }
	        bool done = false;
	        for(int j=0 ; j<m ;j++){
	            if(memory[j] == A[i]){
	                memory.erase(memory.begin()+j);
	                memory.push_back(A[i]);
	                done = true;
	                break;
	            }
	        }
	        if(!done){
	            memory.erase(memory.begin());
	            memory.push_back(A[i]);
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
