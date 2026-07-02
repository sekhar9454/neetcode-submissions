class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int amt , vector<int>&coins){
        if(i == coins.size()) return 0;
        if(amt == 0) return dp[i][amt] = 1;

        if(dp[i][amt] != -1) return dp[i][amt];

        int ways = solve(i+1 , amt , coins);
        if(coins[i] <= amt) ways += solve(i , amt-coins[i] , coins);

        return dp[i][amt] = ways;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n , vector<int>(amount +1 , -1));

        return solve(0 , amount , coins);
    }
};
