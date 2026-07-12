class Solution {
    bool check(string &s1,string &s2){
        if(s1.size() != s2.size()+1)    return false;
        int first=0;
        int second=0;
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++,second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size())   return true;
        return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        int maxi=1;
        vector <int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(1+dp[j] > dp[i] && check(words[i],words[j])){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};