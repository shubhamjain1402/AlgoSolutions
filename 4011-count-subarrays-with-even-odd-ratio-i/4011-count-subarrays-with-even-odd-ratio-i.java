class Solution {
    public int countRatioSubarrays(int[] nums, int a, int b) {
        int n=nums.length;
        int cnt=0;
        for(int i=0;i<n;i++){
            int cnt_odd=0,cnt_even=0;
            for(int j=i;j<n;j++){
                if(nums[j] % 2 == 0) cnt_even++;
                else cnt_odd++;
                if(cnt_even*b <= cnt_odd*a) cnt++;
            }
        }
        return cnt;
    }
}