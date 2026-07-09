class Solution {
    int func(int ind,int buy,int n,vector <int> &prices,vector <vector <int>> &dp){
        if(ind == n)    return 0;
        if(dp[ind][buy] != -1)  return dp[ind][buy];
        int profit=0;
        if(buy){ //if buy-> we can sell else not sell
            profit=max(-prices[ind] + func(ind+1,0,n,prices,dp), 0 + func(ind+1,1,n,prices,dp));
        }
        else{ // if sell -> buy else not buy
            profit=max(prices[ind] + func(ind+1,1,n,prices,dp), 0 + func(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector <vector <int>> dp(n,vector <int>(2,-1));
        return func(0,1,n,prices,dp);
    }
};