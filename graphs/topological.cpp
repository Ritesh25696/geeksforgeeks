/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* You need to complete this function */
void util(vector<int> graph[], int N , vector<int>& vis , stack<int>& S, int u){
    vis[u] = 1;
    for(auto i = graph[u].begin() ; i!=graph[u].end() ; i++){
        if(vis[*i] == 0)util(graph,N,vis,S,*i);
    }
    S.push(u);
}
int * topoSort(vector<int> graph[], int N)
{
   stack<int> S;
   int *ans = new int[N];
   vector<int> visited(N , 0);
   for(int i=0 ; i<N ; i++){
       if(visited[i] == 0)
       util(graph ,N ,visited, S, i);
   }
   int z = 0;
   while(!S.empty()){
       ans[z] = S.top();
       S.pop();
       z++;
   }
   return ans;
}
