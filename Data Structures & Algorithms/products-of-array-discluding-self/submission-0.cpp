class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n+1,1) , suf(n+1 , 1);
        for(int i = 0 ; i < n ; i++){
            pref[i+1] = pref[i] * nums[i];
        }

        for(int i = n-1 ; i>=0 ; i--){
            suf[i] = suf[i+1] * nums[i]; 
        }

        vector<int>ans(n,1);
        for(int i = 0 ; i < n ; i++){
            ans[i] = pref[i] * suf[i+1]; 
        }

        return ans;

    }
};
