class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for (int i = 0; i < m; i++) {
            vector <int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else {
                    int up = 1e9;
                    int left = 1e9;
                    if (i > 0)
                        up = grid[i][j] + prev[j];
                    if (j > 0)
                        left = grid[i][j] + temp[j - 1];
                    temp[j] = min(up, left);
                }
            }
            prev=temp;
        }
        return prev[n - 1];
    }
};