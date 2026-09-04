class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector <int> premax(n);
        vector <int> suffmin(n);
        int maxi=-1;
        int mini=1e9;
        for(int i=0;i<n;i++){
            if(nums[i] > maxi){
                maxi=nums[i];
            }
            if(nums[n-i-1] < mini){
                mini=nums[n-i-1];
            }
            premax[i]=maxi;
            suffmin[n-i-1]=mini;
        }
        for(int i=0;i<n;i++){
            if(premax[i] - suffmin[i] <= k)  return i;
        }
        return -1;
    }
};