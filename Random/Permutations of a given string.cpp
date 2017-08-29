Given a string, print all permutations of a given string.

Input:

The first line of input contains an integer T denoting the number of test cases.
Each test case contains a single string in capital letter.

Output:

Print all permutations of a given string with single space and all permutations should be in lexicographically increasing order.

Constraints:

1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:

Input:
2
ABC

ABSG

Output:
ABC ACB BAC BCA CAB CBA 

ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 
*****************************************************************************************************

#include<iostream>
#include <algorithm>
using namespace std;

void printall(string s){
    do{
        cout<<s<<" ";
    }while(next_permutation(s.begin(), s.end()));
}

int main()
 {
	int t;
	cin>>t;
	for(int i=0 ; i<t ; i++){
	    string s;
	    cin>>s;
	    sort(s.begin() , s.end());
	    printall(s);
	    cout<<endl;
	}
	return 0;
}
