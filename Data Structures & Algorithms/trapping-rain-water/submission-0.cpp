class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int>prefMax(n) , sufMax(n);
        int p1 = h[0] , p2 = h[n-1];

        for(int i = 0 ; i < n ; i++){
            p1 = max(p1, h[i]);
            prefMax[i] = p1;
        }

        for(int i = n-1  ; i >= 0 ; i--){
            p2 = max(p2 , h[i]);
            sufMax[i] = p2;
        }

        int ans  = 0;
        for(int i = 0 ; i < n ; i++){
            int water = min(prefMax[i] , sufMax[i]) - h[i];
            ans += water;
        }


        return ans;
    }
};
