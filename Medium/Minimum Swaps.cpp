Given an array of N distinct elementsA[ ], find the minimum number of swaps required to sort the array.Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

Examples:

Input : {4, 3, 2, 1}
Output : 2
Explanation : Swap index 0 with 3 and 1 with 2 to 
              form the sorted array {1, 2, 3, 4}.

Input : {1, 5, 4, 3, 2}
Output : 2

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1<=T<=100
1<=N<=100
1<=A[] <=1000

Example(To be used only for expected output):
Input:
2
4
4 3 2 1
5
1 5 4 3 2
Output:
2
2

***************************************************************************************************************************

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You are required to complete this method */
int cnt;
void dfs(vector<pair<int, int>> A, vector<bool>& vis, int i){
    cnt++;
    vis[i] = true;
    if(!vis[A[i].second])
    dfs(A , vis , A[i].second);
    return;
}

int minSwaps(int arr[], int N){
    vector<pair<int, int>> A;
    for(int i=0 ; i<N ; i++){
        A.push_back(make_pair(arr[i], i));
    }
    
    sort(A.begin() , A.end());
    cnt = 0;
    int dis = 0;
    vector<bool> vis(N, false);
    for(int i=0 ; i<N ; i++){
        if(!vis[i]){
            dfs(A , vis , i);
            dis += cnt-1;
            cnt = 0;
        }
    }
    return dis;
}
