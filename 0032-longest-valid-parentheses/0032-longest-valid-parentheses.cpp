class Solution {
public:
    int longestValidParentheses(string s) {
        vector <int> st = {-1};
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')    st.push_back(i);
            else{
                st.pop_back();
                if(st.empty())  st.push_back(i);
                else res=max(res,i-st.back());
            }
        }
        return res;
    }
};