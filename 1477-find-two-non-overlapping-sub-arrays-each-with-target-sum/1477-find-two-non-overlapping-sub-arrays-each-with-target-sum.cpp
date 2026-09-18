class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int INF = 1e9;

        vector<int> best(n, INF);

        int left = 0;
        long long sum = 0;

        int minlen = INF;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int len = right - left + 1;

                // previous non-overlapping target subarray exists
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // minimum target-subarray length seen till now
                minlen = min(minlen, len);
            }

            best[right] = minlen;
        }

        return ans == INF ? -1 : ans;
    }
};