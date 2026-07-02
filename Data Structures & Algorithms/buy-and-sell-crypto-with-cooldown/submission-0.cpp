class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int bought , vector<int>&prices){
        if(i >= prices.size()) return 0;

        if(dp[i][bought] != -1) return dp[i][bought];

        int skip = solve(i+1 , bought , prices);
        if(bought){
            int sell = prices[i] + solve(i+2 , 0 , prices);
            return dp[i][bought] = max(sell , skip);
        }
        else{
            int buy = -prices[i] + solve(i+1 , 1 , prices);
            return dp[i][bought] = max(skip , buy);
        }


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n+1 , vector<int>(2,-1));

        return solve(0 , 0 , prices);
    }
};
