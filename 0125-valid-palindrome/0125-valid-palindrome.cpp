class Solution {
public:
    bool isPalindrome(string s) {
       string st = "";
        for (char c : s) {
            if (isalnum(c)) {
                st+= tolower(c);
            }
        }
        int j=st.length()-1;
        for(int i=0;i<st.length()/2;i++){
            if(st[i] != st[j])  return false;
            j--;
        }
        return true;
    }
};