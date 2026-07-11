class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int transaction = 0; transaction < k * 2; transaction++) {
                if (transaction % 2 == 0) {
                    dp[ind][transaction] =
                        max(-prices[ind] + dp[ind + 1][transaction + 1],
                            0 + dp[ind + 1][transaction]);
                } else {
                    dp[ind][transaction] =
                        max(prices[ind] + dp[ind + 1][transaction + 1],
                            0 + dp[ind + 1][transaction]);
                }
            }
        }
        return dp[0][0];
    }
};