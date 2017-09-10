Find the count of numbers less than N having exactly 9 divisors.

Input:
First Line of Input contains the number of testcases. Only Line of each testcase contains the number of members N in the rival gang.

Output:
Print the desired output.

Constraints:

1<=T<=1000
1<=N<=10^12

Example:
Sample Input:

2
40
5
Sample Output:

1
0

*******************************************************************************************************************************************************************88

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isprime(int n){
    for(int i=2 ; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main()
 {
	int t;
	cin>>t;
	vector<long long> A;
	for(int i=2; i<1000000; i++){
	    if(isprime(i))A.push_back(i*i);
	}

	while(t--){
	    int n;
	    cin>>n;
	    int count =0;
	    bool done = false;
	    for(int i=0 ; i<A.size()-1 && !done ; i++){
	        if(pow(A[i],4)<n)count++;
	        for(int j=i+1 ; j<A.size() ; j++){
	            if(j==i+1 && A[j] > n/A[i])done=true;
	            if(A[j] > n/A[i])break;
	            count++;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
