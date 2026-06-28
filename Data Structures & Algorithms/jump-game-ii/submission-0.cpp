class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int i) {
        if(i >= nums.size() - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for(int j = i + 1; j <= min((int)nums.size() - 1, i + nums[i]); j++) {
            int nxt = solve(nums, j);

            if(nxt != INT_MAX)
                ans = min(ans, 1 + nxt);
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return solve(nums, 0);
    }
};