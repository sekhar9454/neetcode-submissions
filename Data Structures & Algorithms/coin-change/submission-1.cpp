class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1 , INT_MAX);
        if(amount == 0) return 0;

        dp[0] = 0;
        // for(int i = 0 ; i < n ; i++) dp[coins[i]] = 1;

        for(int amt = 1 ; amt <= amount ; amt++){
            
            for(int i = 0 ; i < n ; i++){
                if(amt - coins[i] >= 0 && dp[amt - coins[i]]!=INT_MAX){
                    dp[amt] = min(dp[amt] , 1 + dp[amt - coins[i]]); 
                }
            }
        }

        return (dp[amount] == INT_MAX )? -1 : dp[amount];
    }
};
