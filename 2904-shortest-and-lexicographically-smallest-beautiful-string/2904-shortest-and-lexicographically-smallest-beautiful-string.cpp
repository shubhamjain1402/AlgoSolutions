class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, cnt = 0;
        string best = "";
        
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1') cnt++;
            
            while (cnt > k) {
                if (s[left] == '1') cnt--;
                left++;
            }
            
            if (cnt == k) {
                while (s[left] == '0') left++;
                string candidate = s.substr(left, right - left + 1);
                
                if (best.empty() || candidate.size() < best.size() ||
                    (candidate.size() == best.size() && candidate < best)) {
                    best = candidate;
                }
            }
        }
        
        return best;
    }
};
