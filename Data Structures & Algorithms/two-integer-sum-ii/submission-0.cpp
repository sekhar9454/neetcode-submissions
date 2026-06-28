class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(mp.count(target - nums[i])) {
                return {mp[target -  nums[i]] , i+1};
            }

            mp[nums[i]] = i+1;
        }

        return {0,0};
    }
};
