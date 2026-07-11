class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector <vector<int>> dp(n+1,vector<int> (2,0)); //[ind] [buy]
        for(int ind=n-1;ind>=0;ind--){
            dp[ind][1]=max(-prices[ind]+dp[ind+1][0]-fee,0+dp[ind+1][1]); //buy
            dp[ind][0]=max(prices[ind] + dp[ind+1][1],0+dp[ind+1][0]); //sell
        }
        return dp[0][1];
    }
};