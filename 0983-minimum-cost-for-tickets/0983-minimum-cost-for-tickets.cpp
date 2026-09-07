class Solution {
    int func(int ind,vector<int> &days,vector <int> &cost, vector <int> &dp){
        if(ind >= days.size())  return 0;
        if(dp[ind] != -1)   return dp[ind];
        //1 day
        int one=cost[0]+func(ind + 1, days,cost,dp);

        //7day
        int k=ind;
        while(k < days.size() && days[k] < days[ind] + 7)   k++;
        int seven =cost[1]+func(k,days,cost,dp);

        //30
        int j=ind;
        while(j<days.size() && days[ind]+30 > days[j])  j++;
        int th =cost[2]+func(j,days,cost,dp);

        return dp[ind]=min(one,min(seven,th));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector <int> dp(n,-1); 
        return func(0,days,costs,dp);
    }
};