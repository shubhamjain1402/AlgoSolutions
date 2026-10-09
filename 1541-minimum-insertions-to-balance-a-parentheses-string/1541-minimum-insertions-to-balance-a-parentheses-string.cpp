class Solution {
public:
    int minInsertions(string s) {
        stack <char> st;
        int cnt=0;
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i] == '('){ st.push('(');
                i++;
            }
            else if(s[i] == ')' && !st.empty()){
                if(i+1<n && s[i+1] ==')'){
                    i+=2;
                }
                else{
                    cnt++;
                    i++;
                }
                st.pop();
            }
            else if(st.empty()){
                if(i+1<n && s[i+1] == ')'){
                    i+=2;
                    cnt++;
                }
                else{
                    i++;
                    cnt+=2;
                }
            }
        }
        while(!st.empty()){
            st.pop();
            cnt+=2;
        }
        return cnt;
    }
};