class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastmin=-1;
        int lastmax=-1;
        int lastinvalid=-1;
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == minK) lastmin=i;
            if(nums[i] == maxK) lastmax=i;
            if(nums[i] < minK || nums[i] > maxK) lastinvalid=i;
            cnt+=max(0,min(lastmin,lastmax) - lastinvalid);
        }
        return cnt;
    }
};