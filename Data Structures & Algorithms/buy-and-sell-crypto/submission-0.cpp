class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        size_t size = prices.size();
        int bestPrice = prices[0];
        int profit = 0;

        for(int i=1; i<size;i++)
        {
            if (prices[i] < bestPrice)
            {
                bestPrice = prices[i];
            }
            int localProfit = prices[i] - bestPrice;
            if (localProfit > profit)
            {
                profit = localProfit;
            }
        }
        return profit;
    }
};
