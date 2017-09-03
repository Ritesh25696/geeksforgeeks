
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array.
The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whtether it is Pythagorean Triplet or not.

Constraints:
1<=T<=50
 1<=N<=100
 1<=A[i]<=100

Example:
Input:
1
5
3 2 4 6 5
Output:
Yes

**********************************************************************************************************************
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    for(int ct=0 ; ct<t ; ct++){
        int n;
        cin>>n;
        vector<int> A;
        unordered_set<int> mymap;
        for(int i=0 ; i<n ;i++){
            int p;
            cin>>p;
            mymap.insert(p*p);
            A.push_back(p*p);
        }
        bool done = false;
        for(int i=0 ; i<n && !done ; i++){
            for(int j=1; j<n ; j++){
                if(mymap.find(A[i]+A[j])!= mymap.end()){
                    cout<<"Yes"<<endl;
                    done = true;
                    break;
                }
            }
        }
        if(!done)cout<<"No"<<endl;
    }
	return 0;
}
