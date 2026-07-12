class Solution {
public:
    int findMin(vector<int> &nums) {
        int r =  nums.size() - 1 , l = 0 ;
        int ans = INT_MAX;
        while(l<=r){

            int mid = l + (r-l)/2;

            if(nums[mid] <= nums[r]){
                //right sorted
                ans = min(ans, nums[mid]);
                r = mid -1;
            }
            else {
                ans = min(ans , nums[l]);
                l = mid+1;
            }
        }

        return ans;
    }
};
