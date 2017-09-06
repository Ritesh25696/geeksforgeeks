Given a set of positive integers. The task is to complete the function  maxSubarrayXOR which returns an integer denoting the maximum XOR subset value in the given set. 

Examples:

Input: set[] = {2, 4, 5}
Output: 7
The subset {2, 5} has maximum XOR value

Input: set[] = {9, 8, 5}
Output: 13
The subset {8, 5} has maximum XOR value


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the size of the array A[]. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line output will be the maximum XOR subset value in the given set.

Constraints:
1<=T<=100
1<=N<=50

Example(To be used only for expected output):
Input:
2
3
2 4 5
3
9 8 5
Output:
7
13
***********************************************************************************************************************************************************************

int maxSubarrayXOR(int A[], int n)
{
    int idx = 0;
    for(int i=31 ; i>=0 ; i--){
        int maxele = INT_MIN, maxidx = idx;
        for(int j=idx ; j<n ; j++){
            if((A[j] & (1<<i))!=0 && A[j]>maxele){
                maxele = A[j];
                maxidx = j;
            }
        }
        if(maxele == INT_MIN)continue;
        swap(A[idx],A[maxidx]);
        maxidx = idx;
        for(int j=0 ; j<n ; j++){
            if(j != maxidx && (A[j]&(1<<i))!=0)
            A[j]^=A[maxidx];
        }
        idx++;
    }
    int ans = 0;
    for(int k=0 ;k<n ; k++){
        ans^= A[k];
    }
    return ans;
}
