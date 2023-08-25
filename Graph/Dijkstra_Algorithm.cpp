// Using  priority_queue  Time Complexity --> E * log(V)

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int>dist(V,1e9);
        
        dist[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto x:adj[node]){
                
              int edgeWeight = x[1];
              int edgeNode = x[0];
              
              if(dis + edgeWeight < dist[edgeNode]){
                  dist[edgeNode] = dis + edgeWeight;
                  pq.push({dist[edgeNode],edgeNode});
              }
            }
        }
        
        return dist;
    }


// Using Set Data structure 

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    vector<pair<int,int>>adj[vertices];

    for(auto x:vec){
        adj[x[0]].push_back({x[2],x[1]});
        adj[x[1]].push_back({x[2],x[0]});
    }

    set<pair<int,int>>st;
    vector<int>dist(vertices,INT_MAX);

    st.insert({0,source});
    dist[source] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        st.erase(it);

        for(auto x:adj[node]){
            int edgeWeight = x.first;
            int edgeNode = x.second;

            if(dis + edgeWeight < dist[edgeNode]){

                if(dist[edgeNode]!=INT_MAX)st.erase({dist[edgeNode],edgeNode});

                dist[edgeNode] = dis + edgeWeight;
                st.insert({dist[edgeNode],edgeNode});
            }
        }
    }

    return dist;
}
