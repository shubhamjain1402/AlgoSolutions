class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector <unsigned long long> prev(amount+1,0);
        vector <unsigned long long> curr(amount+1,0);
        for(int t=0;t<=amount;t++)  prev[t]=(t%coins[0] == 0);
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                unsigned long long notpick=prev[t];
                unsigned long long pick=0;
                if(coins[ind] <= t) pick=curr[t-coins[ind]];
                curr[t]=pick+notpick;
            }
            prev=curr;
        }
        return prev[amount];
    }
};