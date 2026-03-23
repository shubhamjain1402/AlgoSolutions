class Solution {
private:
    bool check(int start,int V, vector <int> color ,vector<vector<int>>& graph){
        queue <int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacentNode : graph[node]){
                if(color[adjacentNode] == -1){
                    color[adjacentNode]=!color[node];
                    q.push(adjacentNode);
                }
                else if(color[adjacentNode] == color[node])    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V, -1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(check(i,V,color,graph) == false)   return false;
            }
        }
        return true;
    }
};