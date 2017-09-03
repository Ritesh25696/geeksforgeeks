Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.

The result is going to be very large, hence return the result in the form of a string.

Input:

The first line of input consists number of the test cases. The description of T test cases is as follows:

The first line of each test case contains the size of the array, and the second line has the elements of the array.


Output:

In each separate line print the largest number formed by arranging the elements of the array in the form of a string.


Constraints:

1 ≤ T ≤ 70
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 1000


Example:

Input:

2
5
3 30 34 5 9
4
54 546 548 60

Output:

9534330
6054854654
***********************************************************************************************************************************************************************
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(string a, string b){
    string ab = a+b;
    string ba = b+a;
    return ab>ba;
}

int main()
 {
	int t;
	cin>>t;
    for(int ct = 0 ; ct<t ; ct++){
        string result;
        int n;
        cin>>n;
        vector<string> A;
        for(int i=0 ; i<n ; i++){
            int p;
            cin>>p;
            A.push_back(to_string(p));
        }
        sort(A.begin(),A.end(),comp);
        for(int i=0; i<A.size(); i++){
            result+=A[i];
        }
        while(result[0] == '0'){
        result.erase(result.begin());
        } 
        if(result.length() == 0)cout<<"0"<<endl;
        else cout<<result<<endl;
        
    }
	return 0;
}
