Given two integers N and M. The task is to find the longest contiguous subset in binary representation of both the numbers and print its decimal value.

Note: If there are two or more longest common substrings with the same length, the print the maximum value of all the common substrings.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integer N and M as input.

Output:
For each test case, print the decimal value of longest common substring In new line.

Constraints:
1<=T<=1000
1<=N,M<=1018

Example:
Input:
2
10 11
8 16

Output:
5
8

***************************************************************************************************************************

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

string tobin(long long a){
    string temp = "";
    while(a!=0){
        int k = a%2;
        temp+= (k+'0');
        a/=2;
    }
     reverse(temp.begin(),temp.end());
     return temp;
}

int getDeci(string a){
    int ans = 0;
    int j=0;
    for(int i=a.length()-1 ; i>=0 ; i--){
        if(a[i] == '1')ans+=pow(2,j);
        j++;
    }
    return ans;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    long long a,b;
	    cin>>a>>b;
	    string a1 = tobin(a);
	    string b1 = tobin(b);
	    int gres = INT_MIN;
	    int l = a1.length(), len = a1.length();
	    string res = "";
	    bool done = false;
	    while(len>0 && !done){
	        for(int i=0 ; i<l-len+1; i++){
	            string temp = a1.substr(i,len);
	            if(b1.find(temp) != string::npos){
                    res = temp;
	                gres = max(gres , getDeci(temp));
	                done = true;
	            }
	        }
	        len--;
	    }
	    if(res == "")cout<<-1<<endl;
	    else cout<<gres<<endl;
	}
	return 0;
}
