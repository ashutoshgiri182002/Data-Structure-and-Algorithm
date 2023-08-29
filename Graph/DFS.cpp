// dfs traversal for a connected graph


void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ls){

    vis[node] = 1;
    ls.push_back(node);

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int>adj[]){
    vector<int>ls;
    vector<int>vis(V, 0);

    dfs(0, adj, vis, ls);

}

// dfs traversal for a disconnected graph

void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it :adj[node]){
        if(!vis[it]){
            dfs(it, adj,vis,ls);
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int>adj[]){
    vector<int>ls;
    vector<int>vis(V,0);

    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,ls);
        }
    }
}

