bool util(list<int> *adj , vector<string> &visited , int i){
 visited[i] = "gray";
 for(auto j = adj[i].begin() ; j!=adj[i].end() ; j++){
    if(visited[*j] == "gray")return true;
    if(visited[*j] == "white" && util(adj , visited, *j))return true;
 }
    visited[i] = "black";
    return false;
}

bool Graph :: isCyclic()
{
vector<string> visited(V,"white");
for(int i=0 ; i<V ; i++){
    if(visited[i] == "white")
    if(util(adj , visited , i))return true;
}
return false;
}
