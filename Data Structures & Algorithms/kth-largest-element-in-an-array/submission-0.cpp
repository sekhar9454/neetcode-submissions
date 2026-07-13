class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int i : nums) mp[i]++;
        int cnt = 0;
        for(int i = 1000 ; i>= -1000 ;i--){
            if(mp.count(i) > 0){
                cnt += mp[i];
            }

            if(cnt >= k) return i;
        }


        return 0;
    }
};
