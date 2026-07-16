class Solution {
    long long func(int ind, vector<int> &arr, vector<long long> &dp, int n, int k) {
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];

        long long maxAns = 0;
        int maxi = INT_MIN;
        long long len = 0;
        for (int j = ind; j < min(n, ind + k); j++) {
            len++;                          // track current partition length
            maxi = max(maxi, arr[j]);       // track max element in this partition
            long long sum = len * 1LL * maxi + func(j + 1, arr, dp, n, k);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(n, -1);   // memoization array
        return (int)func(0, arr, dp, n, k);
    }
};
