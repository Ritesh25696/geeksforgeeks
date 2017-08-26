A group of connected 1s forms an island now your task is to complete the method findIslands which returns the no of islands present. The function  takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size of the matrix A . 

Input:
The first line of input will be the no of test cases T then T test cases follow. The first line of each test case contains Two space separated integers N and M. Then in the next line are the NxM inputs of the matrix A separated by space .

Output:
The output in the expected output will be the total no of islands present. 

Constraints:
1<=T<=100
1<=N,M<=50
0<=A[][]<=1

Example(To be used only for expected output) :
Input
1
3 3
1 1 0 0 0 1 1 0 1
Output
2

Explanation
The graph will look like
1 1 0
0 0 1
1 0 1
Here  two islands will be formed
First island will be formed by elements { A[0][0] ,  A[0][1], A[1][2], A[2][2] }
Sec island will be formed by  { A[2][0] } 

*****************************************************************************************************

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*you are required to complete this method*/
vector<int> a = {-1,-1,-1,0,0,1,1,1};
vector<int> b = {-1,0,1,-1,1,-1,0,1};
void markconn(int A[MAX][MAX], int N, int M , int x ,int y){
    A[x][y] = 2;
    for(int i=0 ; i<8 ; i++){
        int nx = x+a[i];
        int ny = y+b[i];
        if(nx<0 || ny<0 || nx>=N || ny>=M)continue;
        if(A[nx][ny] == 1)markconn(A,N,M,nx,ny);
    }
}

int findIslands(int A[MAX][MAX], int N, int M)
{
    int count =0 ;
for(int i=0 ; i<N ; i++){
    for(int j=0 ; j<M ; j++){
        if(A[i][j] == 1){
            markconn(A , N , M, i , j);
            count++;
        }
    }
}
return count;
}
