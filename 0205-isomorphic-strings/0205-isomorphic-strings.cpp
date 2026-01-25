class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set <char> a,b;
        for(int i=0;i<s.size();i++){
            a.insert(s[i]);
            b.insert(t[i]);
        }
        return a.size()==b.size();
    }
};