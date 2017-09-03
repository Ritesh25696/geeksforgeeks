
8The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 

Input:
First line contains number of test cases T. Each test case contain the integer value 'N' denoting days followed by an array of stock prices in N days.
Output:
The maximum profit is displayed as shown below. And if there is no profit then print "No Profit".


Constraints:
1 <=T<= 100
2 <=N<= 100
1 <=arr[i]<= 10000


Example

Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:

(0 3) (4 6) 
(1 4) (5 9) 
**********************************************************************************************************************************************************************************

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	 int n;
	 cin>>n;
	 vector<int> A;
	 int mini = 0, max = INT_MAX;
	 for(int i=0 ; i<n ; i++){
	     int p;
	     cin>>p;
	     A.push_back(p);
	 }
	 bool done = false;
	 for(int i=0 ; i<A.size() ; i++){
	     if(A[i] >= max){
	         max = A[i];
	     }
	     else{
	         max = A[i];
	         if(i!= 0 && mini != (i-1)){
	             cout<<"("<<mini<<" "<<i-1<<")"<<" ";
	             done = true;
	         }
	         mini = i;
	     }
	 }
	 if(mini != A.size()-1){
	 cout<<"("<<mini<<" "<<A.size()-1<<")"<<" ";
	     done = true;
	 }
	 if(!done)cout<<"No Profit";
	 cout<<endl;
	}
	return 0;
}
