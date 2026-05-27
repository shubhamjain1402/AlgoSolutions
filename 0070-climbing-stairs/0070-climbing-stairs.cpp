class Solution {
    int func(int n,vector <int> &dp){
        if(n==1 || n == 0)  return 1;
        if (dp[n] != -1) return dp[n]; 
        return dp[n]=func(n-1, dp) + func(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(n,dp);
    }
};