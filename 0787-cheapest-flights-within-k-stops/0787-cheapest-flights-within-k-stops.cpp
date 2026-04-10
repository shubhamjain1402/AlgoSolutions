class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue <pair<int,pair<int,int>>> q;
        q.push({0,{src,0}}); //{stop,{node,dist}}
        vector<int> dist(n,1e9);
        dist[src]={0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops > k) continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edw=it.second;
                if(dis+edw < dist[adjNode] && stops <=k){
                    dist[adjNode]=dis+edw;
                    q.push({stops+1,{adjNode,dis+edw}});
                }
            }
        }
        if(dist[dst] == 1e9)    return -1;
        return dist[dst];

    }

};