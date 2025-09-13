class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_seen[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.size();i++){
            last_seen[s[i]-'a']=i;
            if(last_seen[0]!=-1 && last_seen[1]!=-1 && last_seen[2]!=-1)
            cnt=cnt+(1+min(last_seen[0],min(last_seen[1],last_seen[2])));
        }
        return cnt;
    }
};