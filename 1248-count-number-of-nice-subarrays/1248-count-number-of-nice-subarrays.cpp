class Solution {
public:
    //1 for odd , 0 for even
    int numSubarraysWithLessSum(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int cnt = 0;
        int sum = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            sum += nums[right]%2;
            while (sum > goal) {
                sum = sum - nums[left]%2;
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarraysWithLessSum(nums,k)-numSubarraysWithLessSum(nums,k-1);
    }
};