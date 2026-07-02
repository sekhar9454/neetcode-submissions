class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>seq;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            auto idx = lower_bound(seq.begin() , seq.end() , nums[i]);

            if(idx == seq.end()){
                seq.push_back(nums[i]);
            }
            else{
                *idx = nums[i];
            }
        }

        return seq.size();
    }
};
