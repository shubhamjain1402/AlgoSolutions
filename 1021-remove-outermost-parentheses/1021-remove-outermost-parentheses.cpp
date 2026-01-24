class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        stack <char> st;
        vector <string> str;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
                temp+="(";
            }
            else if(s[i] == ')'){
                st.pop();
                temp+=")";
                if(st.empty()){
                    str.push_back(temp);
                    temp="";
                }
            }
        }
        string ans="";
        for(int i=0;i<str.size();i++){
            ans+=str[i].substr(1,str[i].size()-2);
        }
        return ans;
    }
};