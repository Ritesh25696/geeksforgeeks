Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. The rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[i]<=100

Example:
Input:
2
6
16 17 4 3 5 2
5
1 2 3 4 0
Output:
17 5 2
4 0
**********************************************************************************************************************************************

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t; ct++){
	 int n;
	 cin>>n;
	 vector<int> A;
	 for(int i=0 ; i<n ; i++){
	     int p;
	     cin>>p;
	     A.push_back(p);
	 }
	 vector<int> lead;
	int max = A[n-1];
	 lead.push_back(max);
	 for(int i=n-2; i>=0 ; i--){
	     if(A[i] > max){
	         max = A[i];
	         lead.push_back(A[i]);
	     }
	 }
	 reverse(lead.begin() , lead.end());
	 for(int i=0 ; i<lead.size() ; i++)
	 cout<<lead[i]<<" ";
	 cout<<endl;
	}
}
