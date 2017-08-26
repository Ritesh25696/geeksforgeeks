Given an adjacency matrix (graph), the task is to find the shortest distance of all the vertex's from the source vertex. You are required to complete the function dijkstra which takes 3 arguments. The first argument is the adjacency matrix (graph) , the second argument is the source vertex s and the third argument is V denoting the size of the matrix. The function prints  V space separated integers where i'th integer denotes the shortest distance of the i'th vertex from source vertex.

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow .The first line of each test case contains an integer V denoting the size of the adjacency matrix  and in the next line are V space separated values of the matrix (graph) .The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test case output will be V space separated integers where the ith integer denote the shortest distance of ith vertex from source vertex.

Constraints:
1<=T<=20 
1<=V<=20
0<=s 1<=graph[][]<=1000

Example:
Input
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output
0 25
7 6 0
*************************************************************************************************************************************************************************************

int extractmin(vector<int>&dis , vector<bool>&vis){
    int min = INT_MAX;
    int ind;
    for(int i=0 ; i<dis.size() ; i++){
        if(dis[i] != INT_MAX && !vis[i] && dis[i] < min){min = dis[i];ind = i;}
    }
    return ind;
}    
    
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   vector<bool> vis(V,false);
   vector<int> dis(V,INT_MAX);
   dis[s] = 0;
   int k = 0;
   while(k<V){
       int u = extractmin(dis , vis);
       vis[u] = true;
       k++;
       for(int i=0 ; i<V ; i++){
           if(!vis[i] && graph[u][i] && dis[u] != INT_MAX && dis[u]+graph[u][i]<dis[i])
           dis[i] =dis[u] + graph[u][i];
       }
   }
   for(int i=0 ; i<dis.size() ; i++)cout<<dis[i]<<" ";
  
}
