class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() < 10) return ans;   // safeguard

        unordered_map<string, int> freq;

        // Count occurrences of each substring of length 10
        for(int i = 0; i <= (int)s.size() - 10; i++){
            string str = s.substr(i, 10);
            freq[str]++;
        }

        // Collect substrings that appear more than once
        for(auto &p : freq){
            if(p.second > 1){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
