class Solution {
public:
    int beautySum(string s) {

        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            map<char, int> mpp;
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                int maxFreq = 0, minFreq = INT_MAX;
                for (auto& [ch, f] : mpp) {
                    maxFreq = max(maxFreq, f);
                    minFreq = min(minFreq, f);
                }
                cnt += (maxFreq - minFreq);
            }
        }
        return cnt;
    }
};