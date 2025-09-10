class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int windowstart = 0;
        int cnt = 0;
        int maxlen = 0;
        for (int windowend = 0; windowend < nums.size(); windowend++) {
            if (nums[windowend] == 0)
                cnt++;
            while (cnt > k) {
                if (nums[windowstart] == 0)
                    cnt--;
                windowstart++;
            }
            maxlen = max(maxlen, windowend - windowstart + 1);
        }
        return maxlen;
    }
};