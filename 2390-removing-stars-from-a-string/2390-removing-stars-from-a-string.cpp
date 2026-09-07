class Solution {
public:
    string removeStars(string s) {
        vector <char> a;
        for(char c:s){
            if(isalpha(c))  a.push_back(c);
            else a.pop_back();
        }
        string res="";
        for(auto it: a) res+=it;
        return res;
    }
};