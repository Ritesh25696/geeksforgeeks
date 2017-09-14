Mila has a string(consisting of only lowercase characters) which she wants to gift her best friend Gila. She wants to put the string in a gift box to gift it to Gila. She calculated the width of the gift box to be k units smaller than the length of the string. The string being larger than the box, Mila would now require to remove characters from the string.

Gila once told Mila about her liking for lexicographically smallest strings. Now, Mila wants the string to be lexicographically smallest to make her best friend happy. While calculating the width of the box, Mila made a small mistake. The correction in the value of k is - If the length of the string is a power of 2, reduce k by half, else multiply k by 2.

Help Mila in finding the resulting string.

 

Input:

The first line contains a single integer T denoting the number of test cases. Then T test cases follow. Each of the test cases contains a string and an integer k as described in the problem statement. 
 

Output:

For each test case, print in a new line the resulting string obtained.

If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty print -1.

 

Constraints:

1 <= T <= 10^3

1 <= |String| <=10^6

1 <= k <= 10^6

 

Example:

Input:

2

fooland 2

code 4

Output:

and

cd

Explanation:

For 1st test case:

As the length of the string = 7 which is not a power of 2, hence k = 2*2 = 4. After removing 4 characters from the given string, the resulting string is ‘and’.

For 2nd test case:

As the length of the string = 4, which is 2 to the power 2, hence k = 4/2 = 2.

Hence, resulting string after removal of 2 characters is ‘cd’.

****************************************************************************************************************************************************************

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool ispowertwo(int n){
    int count =0 ;
    while(n!=0){
        if(n&1)count++;
        if(count > 1)return false;
        n>>=1;
    }
    return true;
}

void find(string& s, int k, string& res){
   // cout<<"s is "<<s<<" k is "<<k<<"  res is "<<res<<endl;
    if(k==0){
        res+=s;
        return;
    }
    char min = s[0];
    int idx = 0;
    for(int i=1; i<k+1 ; i++){
        if(s[i] < min){
            min = s[i];
            idx = i;
        }
    }
    res+=min;
    s.erase(0,idx+1);
    find(s,k-idx,res);
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s;
        cin>>k;
        if(ispowertwo(s.length()))k/=2;
        else k*=2;
        string res = "";
        if(s.length() <= k)cout<<-1<<endl;
        else {find(s, k, res) ;cout<<res<<endl;}
    }
	return 0;
}
