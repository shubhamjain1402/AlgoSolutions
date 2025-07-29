class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            int a = nums[i];
            int more = target - a;
            if (mpp.find(more) != mpp.end()) {
                return {mpp[more], i};
            }
            mpp[a] = i;
        }
        return {};
    }
};