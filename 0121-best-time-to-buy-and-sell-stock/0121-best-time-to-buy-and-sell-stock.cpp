class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX, profit = 0;
        // try selling at each point by buying from minTillNow point
        for(int price: prices){
            minTillNow = min(minTillNow, price);
            profit = max(profit, price - minTillNow);
        }
        return profit;
    }
};