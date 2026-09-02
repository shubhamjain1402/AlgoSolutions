class Solution {
public:
    string smallestString(string s) {
        int flag=0;
        string res="";
        int i=0;
        while(i<s.size()){
            if(s[i] != 'a'){
                res+=(char)(s[i]-1);
                flag=1;
                i++;
            }
            else if(s[i] == 'a' && flag==0){
                res+=s[i];
                i++;
            }
            else if(s[i] == 'a' && flag == 1) {
                break;
            }
        }
        int n=s.length();
        if(flag == 0){
            res[n-1]='z';
            return res;
        }
        while(flag != 0 && i<s.size()){res+=s[i];i++;}
        return res;
    }
};