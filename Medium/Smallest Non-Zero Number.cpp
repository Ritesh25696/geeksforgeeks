Given an array of size n your goal is to find a number such that when the number is processed against each array element starting from the 0th index till the (n-1)-th index under the conditions given below, it never becomes negative.

If the number is greater than an array element, then it is increased by difference of the number and the array element.
If the number is smaller than an array element, then it is decreased by difference of the number and the array element.
Input:
First line consists of T, test cases. First line of every test case consists of N, denoting number of elements in array. Second line consists of elements of array.

Output:
Single line output, print the smallest possible number.

Constraints:
1<=T<=100
1<=N<=10^4

Example:
Input:
2
5
3 4 3 2 4
5
1 2 3 4 5
Output:
4
2
********************************************************************************************************************************************************************8

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<float> A;
	    for(int i=0 ; i<n ; i++){
	        float p;
	        cin>>p;
	        A.push_back(p);
	    }
	    float num =0;
	    for(int i=n-1;i>=0 ; i--){
	        num = round((A[i]+num)/2);
	    }
	    cout<<num<<endl;
	}
	return 0;
}
