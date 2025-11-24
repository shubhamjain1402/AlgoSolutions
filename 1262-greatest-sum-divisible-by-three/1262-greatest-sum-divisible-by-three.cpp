class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <int> r1;
        vector <int> r2;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 3 == 1){
                r1.push_back(nums[i]);
            }
            else if(nums[i] % 3 == 2){
                r2.push_back(nums[i]);
            }
            sum+=nums[i]; 
        }
        if(sum% 3 == 0) return sum;
        else if(sum%3 == 1){
            if(r1.size()!= 0 && r2.size() >= 2) return max(sum-r2[0]-r2[1],sum-r1[0]);
            else if(r1.size()!= 0)   return sum-r1[0];
            else if(r2.size() >= 2) return sum-r2[0]-r2[1];
        }
        else if(sum%3 == 2){
            if(r2.size()!= 0 && r1.size() >= 2) return max(sum-r2[0],sum-r1[0]-r1[1]);
            else if(r2.size()!= 0)   return sum-r2[0];
            else if(r1.size() >= 2) return sum-r1[0]-r1[1];
        }
        return sum;
    }
};