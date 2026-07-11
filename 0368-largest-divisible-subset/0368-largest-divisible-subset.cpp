class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)  return {nums[0]};
        vector <int> dp(n,1);
        vector <int> hash(n);
        int maxi=0,lastidx=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++) hash[i]=i;
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]% nums[prev] == 0 && 1+dp[prev] > dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastidx=i;
            }
        }
        vector <int> temp(maxi);
        maxi-=1;
        temp[maxi]=nums[lastidx];
        while(hash[lastidx] != lastidx){
            lastidx=hash[lastidx];
            temp[--maxi]=nums[lastidx];
        }
        return temp;
    }
};