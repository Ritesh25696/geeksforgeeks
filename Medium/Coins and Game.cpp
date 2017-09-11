There are N coins and K people. Each of them can propose a method of distribution of the coins amongst themselves when their chance comes and a vote will occur in favour or against his distribution method between all those members. The person proposing that method of distribution wins the vote if he gets equal or more votes in favour than in against his proposal else he loses. Loosing he would be eliminated and then the next member will now propose his method of distribution amongst the remaining members.

Each person while proposing his method of distribution wants to get the maximum number of coins as well as win the vote.

Each person is smart and knows all the possibilities that may occur from their vote and will cast their vote accordingly.

The first proposal will always be given by 1 if he loses will be followed by 2 and so on (till the Kth person).

In the distribution of the 1st person print the amount of coins each of K people is proposed to get so that he wins the vote.

Input:

The first line of the test case contains an Integer T, denoting the number of test cases. Each the following T lines will contain two space separated Integers N and K denoting the number of coins and the number of person.

Output:

For each of the test case print K space separated Integers denoting the distribution proposed by the 1st person in each line.

Constraints:

1<=T<=100

1<=N<=10^9

1<=K<=10^4

N>=K

Example:

Input

1

100 2

Output

100 0
****************************************************************************************************************************************************************************

#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int p =(k-1)/2;
	    cout<<n-p<<" ";
	    int t=0;
	    for(int i=1;i<k ; i++){
	        cout<<t<<" ";
	        if(t==1)t=0;
	        else t=1;
	    }
	    cout<<endl;
	}
	return 0;
}
