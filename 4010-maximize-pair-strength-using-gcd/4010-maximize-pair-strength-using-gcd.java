class Solution {
    public int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public long maxPairStrength(int[] nums) {
        int n = nums.length;
        long score = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long g = gcd(nums[i], nums[j]);
                score = Math.max(score, (long) ((nums[i] * 1.0 * nums[j]) / Math.pow(g, 2)));

            }
        }
        return score;
    }
}