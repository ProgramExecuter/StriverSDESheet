class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minPrice = prices[0], ans = 0;
        
        for(int i=1; i<n; ++i)
        {
            // Compare minimum price till now and current price
            ans = max(ans, (prices[i]-minPrice));
            // get minimum prices until now
            minPrice = min(minPrice, prices[i]);
        }
        
        return ans;
    }
};