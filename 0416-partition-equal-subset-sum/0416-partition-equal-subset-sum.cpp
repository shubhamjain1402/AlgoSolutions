class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(auto &it: arr) sum+=it;
        if(sum&1) return false;
        vector <vector<bool>> dp(n,vector <bool>(sum/2 +1,0));
        int target=sum/2;
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(arr[0] <= target) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int k=1;k<=target;k++){
                bool notpick=dp[i-1][k];
                bool pick=false;
                if(arr[i] <= k){
                    pick=dp[i-1][k-arr[i]];
                }
                dp[i][k]=pick|notpick;
            }
        }
        return dp[n-1][target];
    }
};