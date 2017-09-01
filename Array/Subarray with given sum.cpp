Given an unsorted array of non-negative integers, find a continuous sub-array which adds to a given number.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:

Corresponding to each test case, in a new line, print the starting and ending positions of first such occuring subarray if sum equals to subarray, else print -1.

Note: Position of 1st element of the array should be considered as 1.

Expected Time Complexity: O(n)

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ an array element ≤ 200

Example:

Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Explanation : 
In first test case, sum of elements from 2nd position to 4th position is 12
In second test case, sum of elements from 1st position to 5th position is 15
************************************************************************************************************************************

#include<vector>
#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    int n , total;
	    cin>>n>>total;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int sum = A[0];
	    int start = 0;
	    bool done = false;
	    for(int i=1 ; i<=A.size() ; i++){
	        while(sum>total && start<i-1){
	            sum = sum-A[start];
	            start++;
	        }
	        if(sum == total){
	            cout<<start+1<<" "<<i<<endl;
	            done = true;
	            break;
	        }
	        if(i<n)sum+=A[i];
	    }
	    if(!done)cout<<-1<<endl;
	}
	return 0;
}
