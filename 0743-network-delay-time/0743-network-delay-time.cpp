class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list: node -> {adjNode, weight}
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // distance array
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // min-heap {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            for(auto [adjnode, edw] : adj[node]){
                if(time + edw < dist[adjnode]){
                    dist[adjnode] = time + edw;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }

        int min_delay = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1; // unreachable node
            min_delay = max(min_delay, dist[i]);
        }
        return min_delay;
    }
};
