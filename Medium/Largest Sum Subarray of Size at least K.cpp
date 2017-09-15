Given an array and a number k, find the largest sum of the subarray containing at least k numbers. It may be assumed that the size of array is at-least k.

Input:​
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. Then the following line contains n space separated integers. The last line of the input contains the number k.

Output:
Print the value of the largest sum of the subarray containing at least k numbers.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=k<=n

Example:
Input:
2
4
-4 -2 1 -3
2
6
1 1 1 1 1 1
2

Output:
-1
6
***********************************************************************************************************************************************************

//get sum of all windows of k length 
//get an array that stores maimus sum possible till that index
//add the maxsum[i-k] value if it makes result more

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    int k;
	    cin>>k;
	    vector<int> maxsum(n);
	    maxsum[0] = A[0];
	    int sum = A[0];
	    for(int i=1 ; i<n ; i++){
	        sum = max(A[i],A[i]+sum);
	        maxsum[i] = sum;
	    }
	    sum = 0;
	    for(int i=0; i<k ; i++){
	        sum+=A[i];
	    }
	    int result = sum;
	    for(int i=k; i<n ; i++){
	        sum = sum - A[i-k] + A[i];
	        result = max(result,sum);
	        result = max(result , sum+maxsum[i-k]);
	    }
	    cout<<result<<endl;
	}
	return 0;
}
