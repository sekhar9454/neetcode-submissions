class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 , n = s.length();
        int l = 0 ;
        vector<int>mp(256 , 0);
        for(int r = 0 ; r < n ;r++){
            mp[s[r]]++;

            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }

            ans = max(ans , r-l+1);
        }

        return ans;
    }
};
