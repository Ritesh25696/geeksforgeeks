Given a sorted array of integers, every element appears twice except for one. Find that single one in linear time complexity and without using extra memory.

 

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.

 


Output:

In each separate line print the number that appears only once in the array.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100000


Example:

Input:

1
11
1 1 2 2 3 3 4 50 50 65 65

Output:

4
*****************************************************************************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n;
	    cin>>n;
	    vector<int> A;
	    for(int i=0 ; i<n ; i++){
	        int p;
	        cin>>p;
	        A.push_back(p);
	    }
	    bool done = false;
	    for(int i=0 ; i<n-1; i+=2){
	        if(A[i] != A[i+1]){
	            done = true;
	            cout<<A[i]<<endl;
	            break;
	        }
	    }
	    if(!done)cout<<A[n-1]<<endl;
	}
	return 0;
}
