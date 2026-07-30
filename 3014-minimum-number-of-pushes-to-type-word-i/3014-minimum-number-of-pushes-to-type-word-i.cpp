class Solution {
    static bool cmp(pair<char,int>& a, pair<char,int>& b) {
        return a.second > b.second; // sort by frequency descending
    }

public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(char ch: word) {
            mpp[ch]++;
        }

        // Copy map into vector
        vector<pair<char,int>> vec(mpp.begin(), mpp.end());

        // Sort by frequency
        sort(vec.begin(), vec.end(), cmp);

        int cost = 0;
        int cnt = 1;
        for(auto &it: vec) {
            if(cnt <= 8) {
                cost += it.second * 1;
            } else if(cnt <= 16) {
                cost += it.second * 2;
            } else if(cnt <= 24) {
                cost += it.second * 3;
            } else {
                cost += it.second * 4;
            }
            cnt++;
        }
        return cost;
    }
};
