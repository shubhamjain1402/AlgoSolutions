class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // remove duplicates
        
        vector<int> rank;
        for (int x : arr) {
            int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            rank.push_back(lb + 1);
        }
        return rank;
    }
};
