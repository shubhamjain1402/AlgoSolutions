class Solution {
public:
    int balancedStringSplit(string s) {
        int bal=0;
        int cnt=0;
        for(char c: s){
            if(c == 'R') bal++;
            else bal--;
            if(bal == 0) cnt++;
        }
        return cnt;
    }
};