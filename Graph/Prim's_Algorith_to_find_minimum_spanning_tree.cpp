
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>>adj[])
    {
         priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
         
         vector<int>vis(V,0);
         
         int sum = 0;
         //{wt,node}
         pq.push({0,0});
         
         while(!pq.empty()){
             auto it = pq.top();
             pq.pop();
             int node = it.second;
             int weight = it.first;
             
             if(vis[node]) continue;
            
             vis[node] = 1;
             sum +=weight;
             
             for(auto x:adj[node]){
                 int adjNode = x[0];
                 int adjWeight = x[1];
                 
                 if(!vis[adjNode]) pq.push({adjWeight,adjNode});
             }
         }
         
         return sum;
    }
};
