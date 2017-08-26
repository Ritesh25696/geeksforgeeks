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
********************************************************************************************************************************************************************
 
 int findmin(int A[] , int st, int end){
    int min = INT_MAX;
    int ind = 0;
    for(int i=st ; i<end ; i++){
        if(A[i] < min){min = A[i]; ind = i;}
    }
    return ind;
}

int minSwaps(int A[], int N){
    int swap = 0;
    for(int i=0 ; i<N ; i++){
        int j = findmin(A,i, N);
        if(i != j){
            int c = A[j];
            A[j] = A[i];
            A[i] = c;
            swap++;
        }
    }
    return swap;
}
