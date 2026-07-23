class Solution {
    int func(int i, int j, vector<vector<int>>& dungeon, int n, int m,vector <vector<int>> &dp) {
        // Guard: Out of bounds
        if (i >= n || j >= m) return INT_MAX;
        if(dp[i][j] != -1)  return dp[i][j];
        // Base Case: The Princess Room
        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - dungeon[i][j]);
        }
        
        // Recursive Step: Ask future paths what they require
        int right = func(i, j + 1, dungeon, n, m,dp);
        int down = func(i + 1, j, dungeon, n, m,dp);
        
        // Calculate health needed BEFORE entering this current room
        int min_on_exit = min(right, down);
        return dp[i][j]=max(1, min_on_exit - dungeon[i][j]);
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector <vector<int>> dp(n,vector <int>(m,-1));
        // Start the journey from the top-left room
        return func(0, 0, dungeon, n, m,dp);
    }
};