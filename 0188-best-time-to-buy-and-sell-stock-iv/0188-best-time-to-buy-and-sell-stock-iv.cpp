class Solution {
    int func(int ind,int transaction,vector <vector<int>> &dp,vector <int>&prices,int n,int k){
        if(ind == n)    return 0;
        if(transaction == k)    return 0;
        if(dp[ind][transaction] != -1)  return dp[ind][transaction];
        if(transaction % 2 == 0){
            return dp[ind][transaction]=max(-prices[ind]+ func(ind+1,transaction+1,dp,prices,n,k),
            0+func(ind+1,transaction,dp,prices,n,k));
        }
        else{
            return dp[ind][transaction]=max(prices[ind]+ func(ind+1,transaction+1,dp,prices,n,k),
            0+func(ind+1,transaction,dp,prices,n,k));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector <vector <int>> dp(n,vector <int>(k*2,-1));
        return func(0,0,dp,prices,n,k*2);
    }
};