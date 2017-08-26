Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju which returns an integer denoting the no of strongly connected components in the graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers N and M . In the next line are N space separated values u,v denoting an edge from u to v.

Output:
For each test case in a new line output will an integer denoting the no of strongly connected components present in the graph.

Constraints:
1<=T<=100
1<=N,M<=20
1<=u,v<=N

Example(To be used only for expected output):
Input:
2
5 5
2 1 1 3 3 2 1 4 4 5
3 3
1 2 2 3 3 1
Output:
3
1
****************************************************************************************************************
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function takes an adjacency list representation of the graph g
    and two integers N and M as specified in the problem statement
    You are required to complete this method. */
   void DFSUtil(int v, bool vis[],vector<int> g1[])
{
    // Mark the current node as visited and print it
    vis[v] = true;

 
    // Recur for all the vertices adjacent to this vertex
    
    for (int i=0; i<g1[v].size();i++){
        if (!vis[g1[v][i]]){
            DFSUtil(g1[v][i], vis,g1);}
        
    }
}

  void fillOrder(int v, bool vis[], stack<int> &Stack,vector<int> g[])
{

    vis[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    
    for(int i=0; i<g[v].size();i++){
        if(!vis[g[v][i]]){
            fillOrder(g[v][i], vis, Stack,g);}
    }
    // All vertices reachable from v are processed by now, push v 
    Stack.push(v);
}

 
int kosaraju(vector<int> g[MAX], int N, int M)
{   int count =0;
    stack<int> Stack;
   bool vis[25];
         memset(vis, false, sizeof(vis));
    // Fill vertices in stack according to their finishing times
    for(int i = 1; i <= N; i++){
        if(vis[i] == false){
            fillOrder(i, vis, Stack,g);
        }
    }
    // Create a reversed graph
   vector<int> g1[MAX];
    
    for(int i=1;i<=N;i++){
        for(auto j=g[i].begin();j<g[i].end();j++){
            g1[*j].push_back(i);
        }
    }
    // Mark all the vertices as not visited (For second DFS)
    memset(vis, false, sizeof(vis));
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (vis[v] == false)
        {  
            DFSUtil(v, vis,g1);
            count++;
        }
       
    }
     
    return count;
    // Your code here
}
