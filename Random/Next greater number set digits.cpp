Given a number n, find the smallest number that has same set of digits as n and is greater than n. If x is the greatest possible number with its set of digits, then print “not possible”.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n,n is the number.

Output:

Print the greater number than n with same set of digits and if not possible then print "not possible" without double quote.

Constraints:

1 ≤ T ≤ 100
1 ≤ n ≤ 100000

Example:

Input
2
143
431

Output
314
not possible
****************************************************************************************************

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findmax(int n){
    vector<int> A;
    while(n != 0){
        A.push_back(n%10);
        n/=10;
    }
    bool ok = false;
    for(int i=1 ; i<A.size() ; i++){
        if(A[i] < A[i-1])ok = true;
    }
    if(ok == false)return -1;
    
    reverse(A.begin(),A.end());
    for(int j = A.size()-2 ; j>=0 ; j--){
        for(int i = A.size()-1 ; i>j ; i--){
            if(A[j] <A[i]){
                int c = A[j];
                A[j] = A[i];
                A[i] = c;
                sort(A.begin()+j+1,A.end());
                int k;
                for(int l=0 ; l<A.size() ; l++){
                    k = k*10 +A[l];
                }
                return k;
            }
        }
    }
}

int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    int n;
	    cin>>n;
	    if(n < 10 )cout<<"not possible"<<endl;
	    int l = findmax(n);
	    if(l == -1)cout<<"not possible"<<endl;
	    else cout<<l<<endl;
	}
	return 0;
}
