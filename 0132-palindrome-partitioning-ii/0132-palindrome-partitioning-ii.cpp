class Solution {
    bool isPal(string &str){
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i] != str[j])    return false;
            i++,j--;
        }
        return true;
    }
    int func(int i,int n,string &s,vector <int> &dp){
        if(i == n)  return 0;
        if(dp[i] != -1) return dp[i];
        string temp="";
        int mincost=INT_MAX;
        for(int j=i;j<=n;j++){
            temp+=s[j];
            if(isPal(temp)){
            int cost=1+func(j+1,n,s,dp);
            mincost=min(mincost,cost);}
        }
        return dp[i]=mincost;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector <int> dp(n,-1);
        return func(0,n,s,dp)-1;
    }
};