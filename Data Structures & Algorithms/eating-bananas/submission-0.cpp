class Solution {
public:

    bool valid(int k , vector<int>&piles , int h){
        int cnt = 0;
        for(int i = 0 ; i <  piles.size() ; i++){
            cnt += (piles[i]+k-1)/k;

            if(cnt > h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin() , piles.end()) , l = 1;

        while(l <= r){
            int k = l+(r-l)/2;

            if(valid(k, piles , h)) {
                r = k -1;
            }
            else l = k+1;
        }

        return l;
    }
};
