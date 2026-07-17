class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int ,int>mp;

        for(int i: nums) mp[i]++;

        for(auto &[k,v] : mp) if(v > 1) return k;
    }
};
