class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 0;
        int cnt = 1 , prev  = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(prev == nums[i]) continue;
            if(nums[i] == prev + 1){
                cnt++;
                prev = nums[i];
            }
            else {
                ans = max(ans ,cnt);
                cnt = 1;
                prev = nums[i];
            }

        }
        ans = max(ans , cnt);

        return ans;
    }
};
