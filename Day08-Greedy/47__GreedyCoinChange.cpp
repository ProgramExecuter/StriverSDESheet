// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end(), greater<int>());
        
        int ans = 0, i = 0;
        
        while(i<n && amount>0) {
            // No of coins we can spend from this denomination
            int noOfCoins = amount/coins[i];
            ans += noOfCoins;
            
            // Reduce these coind from 'amount'
            amount -= noOfCoins*coins[i];
            
            // Move to next denomination
            ++i;
        }
        
        // If we were able to make 'amount'
        // from given denominations
        if(amount == 0)
            return ans;
        
        return -1;
    }
};


// This is not full solution to 'Coin Change', the real solution uses Dynamic Programming 