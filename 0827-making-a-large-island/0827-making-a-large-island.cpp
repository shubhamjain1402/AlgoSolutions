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
    bool isValid(int nrow, int ncol, int n) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = i + dr[ind];
                    int ncol = j + dc[ind];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = i * n + j;
                        int adjnodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
        int maxi = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> component;
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];
                    if (isValid(nrow, ncol, n)) {
                        if (grid[nrow][ncol] == 1) {
                            component.insert(ds.findUPar(nrow * n + ncol));
                        }
                    }
                }
                int sizetotal = 0;
                for (auto it : component) {
                    sizetotal += ds.size[it];
                }
                maxi = max(maxi, sizetotal + 1);
            }
        }
        for (int i = 0; i < n * n; i++) {
            maxi = max(maxi, ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};