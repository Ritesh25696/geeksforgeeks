Given an array having both positive an negative integers . Your task is to complete the function maxLen which returns the length of maximum subarray with 0 sum . The function takes two arguments an array A and n where n is the size of the array A . 

Input:
The first line of input contains an element T denoting the No of test cases. Then T test cases follow. Each test case consist of 2 lines. The first line of each test case contains a number denoting the size of the array A. Then in the next line are space separated values of the array A .

Output:
For each test case output will be the length of the largest subarray which has sum 0 .

Constraints:
1<=T<=100
1<=N<=100
-1000<=A[]<=1000

Example:
Input
1
8
15  -2  2  -8  1  7  10 23

Output
5

Explanation
In the above test case the  largest subarray with sum 0 will be -2  2  -8  1  7

***********************************************************************************************************************************************************

int maxLen(int A[],int n)
{
  map<int , int> mymap;
  int B[n];
  B[0] = A[0];
  for(int i=1 ; i<n ; i++){
      B[i] = A[i] + B[i-1];
  }
  int len = 0;
  for(int i=0 ; i<n ; i++){
      if(B[i] == 0){
          len = max(len, i-0+1);
      }
      if(mymap.find(B[i]) == mymap.end()){
          mymap[B[i]] = i;
      }
      else{
          len = max(len, i-mymap[B[i]]);
      }
  }
  return len;
}
