#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
bool isMultipleOf5(string s) {
    s = string(s.rbegin(), s.rend());
    long long n = 0;
    for(int i = 0; i < s.size(); i++) n += (1ll<<i)*(s[i]-'0');
    while(n > 1 and (n%5 == 0)) n /= 5; 
    return s[s.size()-1] != 48 and n == 1;
}
int dp[1010];
 
int partition(string s, int start) {
    int n = s.size();
    if(start == n) return 0;
    if(dp[start]) return dp[start];
    string part;
    int res = n+1;
    for(int i = start; i < n; i++) {
        part.push_back(s[i]);
        if(isMultipleOf5(part) and (s[i+1] == 49 or i+1 == n))  {
            int resn = partition(s, i+1);
            if(resn != -1)  res = min(res, 1+resn);
        }
    }
    return (dp[start] = ((res == n+1) ? -1 : res));
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    //cout<<isMultipleOf5(s);
    cout<<partition(s, 0);
    return 0;
}
