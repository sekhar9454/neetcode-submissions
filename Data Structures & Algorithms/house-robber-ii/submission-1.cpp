class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n+1 , 0);
        dp[n] = 0;
        dp[n-1] = nums[n-1];
        for(int i  = n-2 ; i >= 0 ; i--){
            dp[i] = max(dp[i+1] , nums[i] + dp[i+2]);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0] , nums[1]);
        int n = nums.size();
        vector<int>arr1(nums.begin() , nums.end() -1) , arr2(nums.begin()+1 , nums.end());

        return max(solve(arr1) , solve(arr2));

    }
};
