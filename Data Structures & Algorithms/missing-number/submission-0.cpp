class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        long long total = (1LL*n*(n+1))/2;

        long long sm = 0;
        for(int i : nums) sm+= i;

        return total - sm;
    }
};
