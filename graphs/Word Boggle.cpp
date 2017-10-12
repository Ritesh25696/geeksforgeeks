Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

** For More Input/Output Examples Use 'Expected Output' option **

********************************************************************************************************************


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> xs = {-1,0,1,1,1,0,-1,-1};
vector<int> ys = {1,1,1,0,-1,-1,-1,0};

bool found(vector<vector<char>> dict, string s , int k){
    for(int i=0 ; i<dict.size() ; i++){
        for(int j=0 ; j<dict[0].size() ; j++){
            if(dict[i][j] == s[0]){
                if(s.length() == 1)return true;
                queue<pair<pair<int,int>,int>> q;
                vector<vector<bool>> vis(dict.size() , vector<bool>(dict[0].size(), false));
                vis[i][j] = true;
                q.push(make_pair(make_pair(i,j),k));
                while(!q.empty()){
                    pair<pair<int, int>, int> fr = q.front();
                    q.pop();
                    int x = fr.first.first;
                    int y = fr.first.second;
                    for(int z = 0 ; z<8 ; z++){
                        int xpos = xs[z] + x;
                        int ypos = ys[z] + y;
                        int l = fr.second;
                        if(xpos>=0 && xpos<dict.size() && ypos>=0 && ypos<dict[0].size() &&!vis[xpos][ypos] && dict[xpos][ypos] == s[l+1]){
                            if(l+1 == s.length()-1)return true;
                            q.push(make_pair(make_pair(xpos,ypos),l+1));
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n;
	    vector<string> s;
	    string str;
	    for(int i=0 ;i<n ; i++){
	        cin>>str;
	        s.push_back(str);
	    }
	    cin>>n>>m;
	    vector<vector<char>> dic(n , vector<char>(m));
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            cin>>dic[i][j];
	        }
	    }
	    int co = 0;
	    vector<string> res;
	    for(int i=s.size()-1 ; i>=0 ; i--)
	    if(found(dic,s[i],0))
	    res.push_back(s[i]);
	   
	    if(res.size() == 0)cout<<-1;
	    else{
	    sort(res.begin(),res.end());
	    res.erase( unique( res.begin(), res.end() ), res.end() );
	    for(int i=0 ; i<res.size() ; i++)cout<<res[i]<<" ";}
	    cout<<endl;
	}
	return 0;
}
