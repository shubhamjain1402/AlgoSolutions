class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(n+1, 0);   // memoization array
        for(int ind=n-1;ind>=0;ind--){
            long long maxAns = 0;
            int maxi = INT_MIN;
            long long len = 0;
            for (int j = ind; j < min(n, ind + k); j++) {
                len++;                          // track current partition length
                maxi = max(maxi, arr[j]);       // track max element in this partition
                long long sum = len * 1LL * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind] = maxAns;
        }
        return (int)dp[0];
    }
};
