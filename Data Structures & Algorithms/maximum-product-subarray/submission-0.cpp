class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int prevMx = mx;
            int prevMn = mn;

            mx = max({nums[i], prevMx * nums[i], prevMn * nums[i]});
            mn = min({nums[i], prevMx * nums[i], prevMn * nums[i]});

            ans = max(ans, mx);
        }

        return ans;
    }
};