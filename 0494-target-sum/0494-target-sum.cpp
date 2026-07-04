class Solution {
    int cnt(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));

        // Base case
        if(arr[0] == 0) dp[0][0] = 2;  // two ways: pick or not pick
        else dp[0][0] = 1;

        if(arr[0] <= target && arr[0] != 0) dp[0][arr[0]] = 1;

        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= target; sum++){
                int notpick = dp[ind-1][sum];
                int pick = 0;
                if(arr[ind] <= sum) pick = dp[ind-1][sum-arr[ind]];
                dp[ind][sum] = pick + notpick;
            }
        }
        return dp[n-1][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        for(auto &it : nums) tot += it;

        // Check validity
        if(tot < abs(target) || (tot + target) % 2 != 0) return 0;

        int S2 = (tot - target) / 2;
        return cnt(nums, S2);
    }
};
