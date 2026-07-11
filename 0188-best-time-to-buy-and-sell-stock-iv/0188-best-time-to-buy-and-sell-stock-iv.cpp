class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(k * 2 + 1, 0) ;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int transaction = 0; transaction < k * 2; transaction++) {
                if (transaction % 2 == 0) {
                    ahead[transaction] =
                        max(-prices[ind] + ahead[transaction + 1],
                            0 + ahead[transaction]);
                } else {
                    ahead[transaction] =
                        max(prices[ind] + ahead[transaction + 1],
                            0 + ahead[transaction]);
                }
            }
        }
        return ahead[0];
    }
};