class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector <int> ahead(2,0); //[ind] [buy]
        vector<int> curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            curr[1]=max(-prices[ind]+ahead[0]-fee,ahead[1]); //buy
            curr[0]=max(prices[ind] + ahead[1],ahead[0]); //sell
            ahead=curr;
        }
        return ahead[1];
    }
};