Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Input:
First line of input contains a single integer T which denotes the number of test cases. T test cases follows. First line of each test case contains two space separated integers N and M. Second line of each test case contains N space separated integers denoting the elements of first array. Third line of each test case contains M space separated integers denoting the elements of second array.

Output:
For each test case, print 1 if there exists any such pair otherwise print -1.

**************************************************************************************************************************

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    int n , m;
	    cin>>n;
	    cin>>m;
	    int suma = 0 , sumb = 0;
	    unordered_set<int> myset;
	    int k;
	    vector<int>A;
	    vector<int>B;
	    for(int i=0 ; i<n; i++){
	        cin>>k;
	        A.push_back(k);
	        myset.insert(k);
	        suma+= k;
	    }
	    for(int i=0 ; i<m ; i++){
	        cin>>k;
	        B.push_back(k);
	        sumb+=k;
	    }
	    bool done = false;
	    for(int i=0 ; i<B.size() ; i++){
	        int tb = sumb-B[i];
	        int ta = suma+B[i];
	        if(abs(ta - tb) %2 == 0){
	            int l = (ta - tb)/2;
	            if(myset.find(l) != myset.end())
	            {cout<<1;
	            done = true;
	            break;}
	        }
	    }
	    if(!done)cout<<-1;
	    cout<<endl;
	}
}
