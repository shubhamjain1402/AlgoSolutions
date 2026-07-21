class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size()-1;
        int m=t.size()-1;
        int left=0,right=0;
        while(left <=n && right <= m){
            if(s[left] == t[right]) left++,right++;
            else right++;
        }
        if(left <= n)   return false;
        return true;
    }
};