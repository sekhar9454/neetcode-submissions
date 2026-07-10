class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>st;

        int n = nums.size() , left = 0 ;
        vector<int>ans;
        for(int right = 0 ; right < n ; right++){
            st.insert(nums[right]);
            if(right - left + 1 == k){
                ans.push_back(*st.rbegin());
                st.erase(st.find(nums[left]));
                left++;
            }

            
        }

        return ans;
    }
};
