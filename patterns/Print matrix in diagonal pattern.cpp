Given a matrix M of n*n size, the task is to complete the function which prints its elements in diagonal pattern as depicted below.

matrix-diagonal-traversal
Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the square matrix. In the next line are N*N space separated values of the matrix M.

Output:
For each test case output will be the space separated values of the matrix elements in diagnol form.

Constraints:
1<=T<=100
1<=n<=20

Example(To be used only for expected output):
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
1 2 4 7 5 3 6 8 9
1 2 3 4

********************************************************************************************************************************
void printMatrixDiagonal(int mat[MAX][MAX], int n)
{
    if(n == 0)return;
    int x = 0 , y = 0;
    cout<<mat[x][y]<<" ";
    x = 0 , y = 1;
    bool dir = true;
    while(x != n && y != n){
        if(dir){
            while(y>0 && x<n-1){
                cout<<mat[x][y]<<" ";
                x++; y--;
            }
            cout<<mat[x][y]<<" ";
            x++;
            if(x >= n){x-- ; y++;}
            dir = false;
        }
        else {
            while(x>0 && y<n-1){
                cout<<mat[x][y]<<" ";
                x--;y++;
            }
            cout<<mat[x][y]<<" ";
            y++;
            if(y>=n){y--;x++;}
            dir = true;
        }
    }
}
