class Solution {
    string LCS(string &s1 ,string & s2 , int n,int m){
        vector <vector <int>> dp(n+1,vector <int> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string res="";
        int i=n,j=m;
        while(i>0 && j> 0){
            if(s1[i-1] == s2[j-1]){
                res+=s1[i-1];
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                res+=s1[i-1];
                i--;
            }
            else{
                res+=s2[j-1];
                j--;
            }
        }
        if(i == 0 && j > 0){
            while(j != 0){
                res+=s2[j-1];
                j--;
            }
        }
        if(i > 0 && j == 0){
            while(i != 0){
                res+=s1[i-1];
                i--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        return LCS(str1,str2,n,m);
    }
};