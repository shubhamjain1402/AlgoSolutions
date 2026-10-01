class Solution {
    int sum(int n){
        int sum=0;
        while(n != 0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sum(nums[i]) == i)    return i;
        }
        return -1;
    }
};