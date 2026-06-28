class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int>ans = nums;
        sort(ans.begin() , ans.end());
        ans.erase(unique(ans.begin() ,ans.end()) , ans.end());

        return nums.size() != ans.size();
    }
};