
Given a number N. You are tasked with finding the smallest number S, such that N is a factor of S! (S factorial). N can be very large.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n.

Output:
Print the smallest number, such that N is a factor of S!

Constraints:
1<=T<=100
1<=N<=10^12

Example:
Input:
2
6
800

Output:
3
10
********************************************************************************************************
#include<iostream>
#include<map>
using namespace std;

void Factors(long long int n , map<long long int , int>& factors){
    while(n%2 == 0){
        n/=2;
        if(factors.find(2) == factors.end())factors[2] = 0;
        factors[2]++;
    }
    for(long long int i=3 ; i*i<=n ; i+=2){
        while(n%i == 0){
            if(factors.find(i) == factors.end())factors[i] = 0;
            factors[i]++;
            n/=i;
        }
    }
    if(n > 1){
        if(factors.find(n) == factors.end())factors[n] = 0;
            factors[n]++;
    }
}

long long int leg(long long int a  , long long int n){
    long long int res = 0;
    while(n >=a){
        res += n/a;
        n/=a;
    }
    return res;
}

bool check(map<long long int , int> factors , long long int n){
    for(auto i=factors.begin() ; i!= factors.end() ; i++){
	        if(leg(i->first , n) < i->second)
	        return false;
	    }
	    return true;
}

long long int search(long long int st , long long int end , map<long long int , int> factors){
    long long int mid = st + (end-st)/2;
    if(!check(factors , mid))
    return search(mid+1 ,end , factors);
    
    if(st == mid)return mid;
    
    else return search(st , mid , factors);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    if(n == 0){cout<<0;continue;}
	    map<long long int , int>factors;
	    Factors(n , factors);
	    cout<<search(1 , n, factors)<<endl;
	}
	return 0;
}
