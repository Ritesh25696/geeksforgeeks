Traverse a 4x4 matrix of integers in spiral form.

Input: The first line of input contains an integer T denoting the number of test cases. First four lines of the test case will contain four elements each.
Output: Spiral array will be displayed in a single line.
Constraints:

1 <=T<= 100

1 <=N<= 100
Example:

Input:
1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 

****************************************************************************************************************************************************************************

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct = 0; ct<t ; ct++){
	   vector<vector<int>> A(4 , vector<int> (4,0));
	   for(int i=0 ; i<4 ; i++){
	       for(int j=0 ; j<4 ; j++){
	           int p;
	           cin>>p;
	           A[i][j] = p;
	       }
	   }
    int top = 0 , bottom = A.size()-1, left = 0 , right = A[0].size()-1 , dir =0 ;
    while(top<=bottom && left<=right){
        if(dir == 0){
            for(int i=left ; i<=right ; i++){
                cout<<A[top][i]<<" ";}
                top++;
                dir = 1;
        }
        else if(dir == 1){
            for(int i=top ; i<=bottom ; i++){
                cout<<A[i][right]<<" ";}
                right--;
                dir = 2;
        }
        else if (dir == 2){
            for(int i=right ; i >= left ; i--){
                cout<<A[bottom][i]<<" ";}
                bottom--;
                dir = 3;
            
        }
        else{
            for(int i=bottom; i>= top ; i--){
                cout<<A[i][left]<<" ";}
                left++;
                dir = 0;
            
        }
    }
    cout<<endl;
	}
	return 0;
}
