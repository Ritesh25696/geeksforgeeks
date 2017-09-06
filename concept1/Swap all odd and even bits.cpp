Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 ( 0 0 0 1 0 1 1 1 ), it should be converted to 43 ( 0 0 1 0 1 0 1 1 ). Here every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N, where N is the number of coins.

Output:

Corresponding to each test case, print in a new line, the converted number .

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input
2
23
2

Output
43
1

**************************************************************************************************************************************************
include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int evenpos = n&0xAAAAAAAA;
	    int oddpos = n&0x55555555;
	    oddpos<<=1;
	    evenpos>>=1;
	    cout<<(oddpos|evenpos)<<endl;
	}
	return 0;
}
