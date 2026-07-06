class Solution {
    bool check(int start,int V,vector <int> &color,vector <vector <int>> &graph){
        queue <int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int clr=color[node];
            for(auto &it:graph[node]){
                if(color[it]==-1){
                    color[it]=!clr;
                    q.push(it);
                }
                else if(color[it] == clr)   return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector <int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,V,color,graph)==false)   return false;
            }
        }
        return true;
    }
};