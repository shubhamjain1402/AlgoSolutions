class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector <int> vis(v,0);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
    void dfs(int node,vector < vector<int>> &adj , vector <int> &vis){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it])    dfs(it,adj,vis);
        }
    }
};