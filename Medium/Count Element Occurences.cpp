Given an array of size n, find all elements in array that appear more than n/k times.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. Then the next line contains n space separated integers forming the array. The last line of input contains an integer k.

Output:
Print the count of elements in array that appear more than n/k times.

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=a[i]<=10^5
1<=k<=N

Example:
Input:
2
8
3 1 2 2 1 2 3 3
4
4
2 3 3 2
3

Output:
2
2

*********************************************************************************************************************************8
#include<unordered_map>
#include<vector>
void moreThanNdK(long long int a[], long long int n, long long int k)
{
     unordered_map<long long int, int> can;
     for(int i=0 ; i<n ; i++){
         if(can.find(a[i]) != can.end()){
             can[a[i]]++;
         }
         else{
             if(can.size() < k)
             can[a[i]] = 1;
             
             else{
                 vector<int> z;
                 for(auto j=can.begin() ; j!=can.end() ; j++){
                     j->second--;
                     if(j->second == 0)z.push_back(j->first);
                 }
                 for(int l=0 ; l<z.size() ; l++)can.erase(z[l]);
             }
         }
          
     }
     for(auto j=can.begin() ; j!=can.end() ; j++){
                     cout <<j->first<<" "<<j->second<<endl;
                 }
}
