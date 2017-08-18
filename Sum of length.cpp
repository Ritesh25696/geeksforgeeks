
Given an array. Write a program to calculate the sum of lengths of contiguous subarrays having all distinct elements.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains a single integer N which denotes the number of elements in the array. Second line of each test case contains N space separated integers.
Output:
For each test case, print the sum of lengths of contiguous subarrays having all distinct elements.

Constraints:
1<=T<=100
1<=N<=105

Example:
Input:
3
3
1 2 3
3
1 2 1
4
1 2 3 4
Output:
10
7
20

**For More Examples Use Expected Output**

***********************************************************************************************************************

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int lengths(vector<int> &arr){
   unordered_set<int> s;
   int j = 0, ans = 0, n= arr.size();

    for (int i=0; i<n; i++)
    {
 
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
 
        ans += ((j - i) * (j - i + 1))/2;
        s.erase(arr[i]);
    }
 
    return ans;
}

int main() {
    int T;
    cin>>T;
    int n,k;
    vector<int> A;
    for(int i=0 ; i<T ; i++){
        cin>>n;
        A.clear();
        for(int j=0 ; j<n ; j++){
            cin>>k;
            A.push_back(k);
        }
    cout<<lengths(A)<<endl;
    }
	return 0;
}
