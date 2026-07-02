class Solution {
public:
    
    unordered_map<string , int>dp;
    int solve(int i , int tar , vector<int>&nums){
        if(i < 0){
            if(tar == 0) return 1;
            else return 0;
        }
        string key = to_string(i) + '#' +  to_string(tar);

        if(dp.count(key)) return dp[key];

        int ways = solve(i-1 , tar + nums[i] , nums) + solve(i-1 , tar - nums[i] , nums);

        return dp[key] = ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return solve( n-1 , target , nums);
    }
};
