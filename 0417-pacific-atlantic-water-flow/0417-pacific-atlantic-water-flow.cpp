#include <bits/stdc++.h>
using namespace std;

// Custom hash for pair<int,int>
struct pair_hash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
    unordered_set<pair<int,int>, pair_hash> findOneOcean(queue<pair<int,int>> &q,
                                                        vector<vector<int>> &heights,
                                                        int m, int n) {
        unordered_set<pair<int,int>, pair_hash> st;
        vector<vector<int>> vis(m, vector<int>(n, -1));

        int delrow[4] = {0,1,0,-1};
        int delcol[4] = {1,0,-1,0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vis[row][col] = 1;
            st.insert({row,col});

            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                   vis[nrow][ncol] == -1 &&
                   heights[row][col] <= heights[nrow][ncol]) {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return st;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<pair<int,int>, pair_hash> pst;
        unordered_set<pair<int,int>, pair_hash> ast;
        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        int m = heights.size();
        int n = heights[0].size();

        for(int i=0; i<m; i++) {
            pq.push({i,0});
            aq.push({i,n-1});
        }
        for(int j=0; j<n; j++) {
            pq.push({0,j});
            aq.push({m-1,j});
        }

        pst = findOneOcean(pq, heights, m, n);
        ast = findOneOcean(aq, heights, m, n);

        vector<vector<int>> ans;
        for(auto it : pst) {
            if(ast.find(it) != ast.end()) {
                ans.push_back({it.first, it.second});
            }
        }
        return ans;
    }
};
