class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(k * 2 + 1, 0) , curr(k * 2 + 1, 0) ;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int transaction = 0; transaction < k * 2; transaction++) {
                if (transaction % 2 == 0) {
                    curr[transaction] =
                        max(-prices[ind] + ahead[transaction + 1],
                            0 + ahead[transaction]);
                } else {
                    curr[transaction] =
                        max(prices[ind] + ahead[transaction + 1],
                            0 + ahead[transaction]);
                }
            }
            ahead=curr;
        }
        return ahead[0];
    }
};