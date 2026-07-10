class Solution {
    int func(int ind,int buy,int cap,vector <int> &prices,vector <vector <vector <int>>> &dp,int &n){
        if(cap == 0) return 0;
        if(ind == n) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + func(ind+1,0,cap,prices,dp,n),
                                        0+func(ind+1,1,cap,prices,dp,n));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+func(ind+1,1,cap-1,prices,dp,n),
                                    0+func(ind+1,0,cap,prices,dp,n));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0,1,2,prices,dp,n);   
    }
};