class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int cnt=0;
        int maxi=0;
        for(int right=0;right <nums.size();right++){
            if(nums[right] == 0)    cnt++;
            if(cnt > k){
                if(nums[left] == 0) cnt--;
                left++;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};