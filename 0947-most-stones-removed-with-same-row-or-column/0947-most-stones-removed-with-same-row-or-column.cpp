class DSU {
    vector<int> parent;

public:
    vector<int> size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DSU ds(maxrow+maxcol+1);
        set <int> stonenode;
        for(auto it: stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionBySize(noderow,nodecol);
            stonenode.insert(noderow);
            stonenode.insert(nodecol);
        }
        int cnt=0;
        for(auto it: stonenode){
            if(ds.findUPar(it) == it)  cnt++;
        }
        int n=stones.size();
        return n-cnt;
    }
};