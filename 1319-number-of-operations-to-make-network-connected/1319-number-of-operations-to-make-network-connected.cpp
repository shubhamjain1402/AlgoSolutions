class DSU{
    private:
    vector <int> parent,size;
    
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int  findUPar(int node){
        if (parent[node] == node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
        else{
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int cntextra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u) == ds.findUPar(v))    cntextra++;
            else{
                ds.unionBySize(u,v);
            }
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i)    nc++;
        }
        int ans=nc-1;
        if(cntextra >= ans) return ans;
        return -1;
    }
};