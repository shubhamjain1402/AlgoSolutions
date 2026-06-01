class Solution {
    int func(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int nottake = 0 + prev;
            int curri = max(take, nottake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> case1(nums.begin() + 1, nums.end()); // exclude first
        vector<int> case2(nums.begin(), nums.end() - 1); // exclude last

        return max(func(case1), func(case2));
    }
};