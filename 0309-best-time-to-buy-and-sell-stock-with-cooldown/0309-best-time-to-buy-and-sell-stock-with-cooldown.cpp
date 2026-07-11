class Solution {
    int func(int ind,int buy , int cooldown , vector <vector<vector <int>>> &dp, vector <int> &prices, int &n){
        if(ind == n)    return 0;
        if(dp[ind][buy][cooldown] != -1)    return dp[ind][buy][cooldown];
        if(cooldown == 1)  return dp[ind][buy][cooldown]=func(ind+1,buy,0,dp, prices , n);
        else if(buy == 0){
            return dp[ind][buy][cooldown]=max(-prices[ind] + func(ind+1,1,0,dp,prices,n),
            0+ func(ind+1,0,0,dp,prices,n));
        }
        else {
            return dp[ind][buy][cooldown]= max(prices[ind] + func(ind+1,0,1,dp,prices,n),
            0+ func(ind+1,1,0,dp,prices,n));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector <vector<vector <int>>> dp(n,vector <vector<int>>(2,vector <int>(2,-1)));
        return func(0,0,0,dp,prices,n);
    }
};