class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> b;
        int remainder = 0;  // track only mod 5
        for (int i = 0; i < nums.size(); i++) {
            remainder = (remainder * 2 + nums[i]) % 5;
            b.push_back(remainder == 0);
        }
        return b;
    }
};