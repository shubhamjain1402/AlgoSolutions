class Solution {
    // int func(string&s,string&t,int i,int j){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(s[i]==t[j])  return func(s,t,i-1,j-1)+func(s,t,i-1,j);
    //     else    return func(s,t,i-1,j);
    // }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // return func(s,t,n-1,m-1);
        vector <double> dp(m+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1])
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return (int)dp[m];
    }
};