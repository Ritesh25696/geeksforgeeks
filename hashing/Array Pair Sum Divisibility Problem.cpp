Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains an integer n denoting the size of the array. The next line contains the n space separated integers forming the array. The last line contains the value of k.

Output:
Print "True" (without quotes) if given array can be divided into pairs such that sum of every pair is divisible by k or else "False" (without quotes).

Constraints:
1<=T<=100
2<=n<=10^5
1<=a[i]<=10^5
1<=k<=10^5

Example:
Input:
2
4
9 7 5 3
6
4
91 74 66 48
10

Output:
True
False
**************************************************************************************************************************

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    for(int i=0 ; i<t ; i++){
        int n;
        cin>>n;
        vector<int> A;
        unordered_map<int , int> mymap;
        for(int i=0 ; i<n ; i++){
            int k;
            cin>>k;
            A.push_back(k);
        }
        int b;
        cin>>b;
        for(int i=0 ; i<A.size() ; i++){
            int k;
            if(A[i] > 0)
            k = A[i]%b;
            else{
                int z = A[i]*-1;
                k = b-(z%b);
            }
            A[i]  = k;
            if(mymap.find(k) == mymap.end()){
                mymap[k] = 1; 
            }
            else mymap[k]++;
        }
        bool done = false;
        for(int i=0 ; i<A.size() ; i++){    
            if(mymap.find(A[i]) != mymap.end()){
                mymap[A[i]]--;
                if(mymap[A[i]] == 0)mymap.erase(A[i]);
                int p = b - A[i];
                if(A[i] == 0)p = 0;
                if(mymap.find(p) == mymap.end()){done = true;cout<<"False";break;}
                mymap[p]--;
                if(mymap[p] == 0)mymap.erase(p);
            }
        }
        if(!done)
        cout<<"True";
        cout<<endl;
    }
	return 0;
}
