class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0 , n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(i <= canReach){
                canReach = max(canReach , i + nums[i]);
            }
            else return false;

            if(canReach >= n-1) return true;
        }

        return false;
    }
};
