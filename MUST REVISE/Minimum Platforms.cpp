Given arrival and departure times of all trains that reach a railway station, find the minimum number of platforms required for the railway station so that no train waits.

Input:

First line will contain a number T, the number of test cases.
Each test case will contain a number N, the number of trains.
Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
NOTE: Time intervals are in 24 hour format(hhmm),preceding zeros are insignificant.
Consider the example for better understanding of input.

Output:

Print the required answer in separated line.

Constraints:

1<=T<=80
1<=N<=5000

1<=A[i]<=5000

Example:

INPUT:

1
6 
900  940 950  1100 1500 1800
910 1200 1120 1130 1900 2000

OUTPUT:

3

***********************************************************************************************************************

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n;
	    cin>>n;
	    vector<int> arr , dept;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        arr.push_back(p);
	    }
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        dept.push_back(p);
	    }
	   sort(dept.begin() , dept.end());
	   sort(arr.begin() , arr.end());
	   int plat = 1 , res = 1;
	   int i=1 , j=0;
	   while(i<n && j<n){
	       if(arr[i] < dept[j]){
	           plat++;
	           i++;
	           res = max(res,plat);
	       }
	       else{
	           plat--;
	           j++;
	       }
	   }
	   cout<<res<<endl;
	}
	return 0;
}
