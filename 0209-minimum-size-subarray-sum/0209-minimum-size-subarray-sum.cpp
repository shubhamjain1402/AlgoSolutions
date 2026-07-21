class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left=0;
        int mini=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            if(sum>= target){
                while(sum >= target){
                    mini=min(mini,right-left+1);
                    sum-=nums[left];
                    left++;
                }
            }
        }
        return mini==INT_MAX ? 0: mini;
    }
};