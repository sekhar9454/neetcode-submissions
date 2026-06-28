class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int>prefMin(n,0);

        int p1 = p[0] , ans = 0;
        for(int i = 0 ; i < n ; i++){
            p1 = min(p1 , p[i]);
            ans = max(ans , p[i] - p1);
        }

        return ans;
    }
};
