Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

                                {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };

                        x=4, y=4, color=3 

                               {{1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 0, 0},
                     {1, 0, 0, 1, 1, 0, 1, 1}, 
                     {1, 3, 3, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 3, 3, 0},
                     {1, 1, 1, 1, 1, 3, 1, 1},
                     {1, 1, 1, 1, 1, 3, 3, 1}, };


Note: Use zero based indexing.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=100
1<=M[][]<=100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4

**************************************************************************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;

vector<int> q = {-1,0,1,0};
vector<int> w = {0,-1,0,1};

void change(vector<vector<int>>& A, int x , int y , int k , int l){
    if(A[x][y] == l)A[x][y] = k;
    else return;
    for(int i=0 ; i<q.size(); i++){
        int xpos = x+q[i];
        int ypos = y+w[i];
        if(xpos>=0 && xpos<A.size() && ypos>=0 && ypos<A[0].size()&& A[xpos][ypos]==l){
            change(A,xpos,ypos,k,l);
        }
    }
    return;
}

int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> A(n, vector<int>(m,0)); 
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            int p;
	            cin>>p;
	            A[i][j] = p;
	        }
	    }
	    int x, y, k;
	    cin>>x>>y>>k;
	    change(A,x,y,k,A[x][y]);
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            cout<<A[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
