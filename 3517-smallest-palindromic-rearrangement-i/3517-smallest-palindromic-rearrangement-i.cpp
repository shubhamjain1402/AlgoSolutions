class Solution {
public:
    string smallestPalindrome(string s) {
        vector <int> hash(26,0);
        for(int c: s){
            hash[c-'a']++;
        }
        string left_s="";
        char odd='0';
        for(int i=0;i<26;i++){
            if(hash[i]%2 == 0){
                left_s.append(hash[i]/2, char(i+'a'));
            }
            else {
                left_s.append(hash[i]/2, char(i+'a'));
                odd=i+'a';
            }
        }
        string copy=left_s;
        reverse(left_s.begin(),left_s.end());
        if(odd != '0'){
            copy+=odd;
        }
        copy+=left_s;
        return copy;
    }
};