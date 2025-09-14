class Solution {
public:
    int subarraysWithLessthanEqualKDistinct(vector<int>& nums, int k) {
        int cnt = 0, l = 0, r = 0;
        map<int, int> mpp;
        while (r < nums.size()) {
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithLessthanEqualKDistinct(nums,k)-subarraysWithLessthanEqualKDistinct(nums,k-1);
    }
};
