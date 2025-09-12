class Solution {
public:
    int numSubarraysWithLessSum(vector<int>& nums, int goal) {
        if(goal < 0)    return 0;
        int cnt=0;
        int sum=0;
        int left=0,right=0;
        while(right < nums.size()){
            sum+=nums[right];
            while(sum > goal){
                sum=sum-nums[left];
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithLessSum(nums,goal)-numSubarraysWithLessSum(nums,goal-1);
    }
};