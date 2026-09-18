class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<long long> st;
        for (int i = 0; i < nums.size() - 1; i++) {
            long long sum = (long long)nums[i] + nums[i + 1];

            if (st.find(sum) != st.end()) {
                return true;
            }

            st.insert(sum);
        }

        return false;
    }
};