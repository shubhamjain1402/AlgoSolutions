class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int left=0;
        unordered_set <long long> st;
        if(nums.size() == 2)    return false;
        int length=0;
        long long sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            length++;
            if(length > 2){
                sum-=nums[left];
                left++;
                length--;
            }
            if(st.find(sum) != st.end())    return true;
            if(length == 2) st.insert(sum);
        }
        return false;
    }
};