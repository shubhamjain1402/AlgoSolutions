class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)    return strs[0];
        sort(strs.begin(),strs.end());
        string s=strs[0];
        string t=strs[strs.size()-1];
        string res="";
        for(int i=0;i<strs[0].size();i++){
            if(s[i] == t[i])    res+=s[i];
            else break;
        }
        return res;
    }
};