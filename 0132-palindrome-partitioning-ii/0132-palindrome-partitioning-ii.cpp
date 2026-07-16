class Solution {
    bool isPal(string& str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++, j--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            string temp = "";
            int mincost = INT_MAX;
            for (int j = i; j <= n - 1; j++) {
                temp += s[j];
                if (isPal(temp)) {
                    int cost = 1 + dp[j + 1];
                    mincost = min(mincost, cost);
                }
            }
            dp[i] = mincost;
        }
        return dp[0] - 1;
    }
};