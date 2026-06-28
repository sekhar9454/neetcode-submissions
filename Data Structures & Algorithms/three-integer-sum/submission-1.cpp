class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        // nums.erase(unique(nums.begin() , nums.end()) , nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        
        for(int i = 0 ; i < n-1; i++){
            unordered_map<int,int>mp;
            int target = - nums[i];
            for(int j = i+1 ; j < n ; j++){

                if(mp.count(target-nums[j]) > 0 ) {
                    vector<int>elem = {nums[i] , target - nums[j] , nums[j]};
                    sort(elem.begin() , elem.end());
                    ans.insert(elem);
                }
                mp[nums[j]] = j;
            }
        }
        vector<vector<int>> anss(ans.begin() , ans.end());
        return anss;
    }
};
