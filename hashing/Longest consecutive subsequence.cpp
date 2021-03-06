Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:

The first line of input contains T, number of test cases.

First line of line each test case contains a single integer N.

Next line contains N integer array.

Output:

Print the output of each test case in a seprate line.

Constraints:

1<=T<=100
1<=N<=100
0<=a[i]<=500

Example:

Input:

2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:

6
4
***************************************************************************************************************************

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
 {
    int t;
    cin>>t;
    for(int i=0 ; i<t ; i++){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0 ; i< n ; i++){
            int k;
            cin>>k;
            A.push_back(k);
        }
        sort(A.begin(),A.end());
        int m = 1 , gm = 1;
        for(int i=1 ; i<A.size() ; i++){
            if(A[i] == A[i-1]+1)
                m++;
            else m = 1;
            if(m > gm)gm = m;
        }
        cout<<gm<<endl;
    }
	return 0;
}
