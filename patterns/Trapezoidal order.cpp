Trapezoidal order. Citi and CGI

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a = 1;
    int b = (n*n)+1;
    
    for(int i= n ; i>0 ; i--){
        
        for(int j=0 ; j<n-i ; j++)cout<<"  ";
        
        for(int j=0 ; j< i ; j++)
        cout<<a++<<"*";
        
        
        for(int j=1 ; j<i ; j++)
        cout<<b++<<"*";
        
        cout<<b;
        
        b-=2*(i-1);
        cout<<endl;
    }
    
    return 0;
}
