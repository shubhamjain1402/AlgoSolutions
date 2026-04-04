class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int prf=prices[i]-cost;
            if(prf >0){
                profit+=prf;
            }
            cost=prices[i];
        }
        return profit;
    }
};