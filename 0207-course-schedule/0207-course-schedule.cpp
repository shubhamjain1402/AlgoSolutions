class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1; // mark as visiting
        for (auto adjacentNode : adj[node]) {
            if (vis[adjacentNode] == 0) {
                if (dfs(adjacentNode, vis, adj))
                    return true;
            } else if (vis[adjacentNode] == 1) {
                // cycle detected
                return true;
            }
        }
        vis[node] = 2; // mark as visited
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            int x = p[0];
            int y = p[1];
            adj[y].push_back(x);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, adj) == true)
                    return false;
            }
        }
        return true;
    }
};