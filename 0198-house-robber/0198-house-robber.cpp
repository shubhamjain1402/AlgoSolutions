class Solution {
    int func(int ind,vector <int> & dp,vector <int> &nums){
        if(ind == 0)    return nums[ind];
        if(ind == -1)   return 0;
        if(dp[ind] != -1)   return dp[ind];
        int pick=nums[ind]+func(ind - 2,dp,nums);
        int notpick=0+func(ind-1,dp,nums);
        return dp[ind]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp(n+1,-1);
        return func(n-1,dp,nums);
    }
};