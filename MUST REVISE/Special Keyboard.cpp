Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed. 

If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of key.

Output:

Print maximum number of A's.  Print -1, if N is greater than 75.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 75

Example:

Input:
2
3
7

Output:
3
9

Explanation:

Input:  N = 3
Output: 3
We can at most get 3 A's on screen by pressing 
following key sequence.
A, A, A

Input:  N = 7
Output: 9
We can at most get 9 A's on screen by pressing 
following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
**********************************************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int ct=0 ; ct<t ; ct++){
	    int n;
	    cin>>n;
	    vector<int> M(n+1,0);
	    bool done = false;
	    if(n > 75){
	        cout<<-1<<endl;
	        done = true;
	    }
      if(!done)
      { for(int i=1 ; i<=6; i++)
	    M[i] = i;
	    for(int i=7 ; i<=n ; i++){
	     for(int b=i-3; b>=1; b--){
	         M[i] = max(M[i],(i-b-1)*M[b]);
	     }   
	    }
	    cout<<M[n]<<endl;}
	}
	return 0;
}
