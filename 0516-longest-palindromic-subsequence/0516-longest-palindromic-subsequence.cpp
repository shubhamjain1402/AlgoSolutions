class Solution {
    string LCS(string &s1,string &s2, int n){
        vector <vector<int>> dp(n+1,vector <int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int len=dp[n][n];
        int ind=len-1;
        string res="";
        for(int i=0;i<len;i++) res+='@';
        int i=n,j=n;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                res[ind]=s1[i-1];
                ind--;
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])    i--;
            else j--;
        }
        return res;
    }
public:
    int longestPalindromeSubseq(string s) {
         string r=s;
         reverse(r.begin(),r.end());
         int n=s.size();
         return LCS(s,r,n).size();
    }
};