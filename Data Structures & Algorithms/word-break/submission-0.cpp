class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string , int>mp;
        vector<bool>dp(n+1 , false);
        for(string word : wordDict){
            mp[word] = 1;
        }

        dp[0] = true;

        for(int i = 1 ; i<=n ;i++){
            for(int j = 1 ; j <= i ; j++){
                if(mp.count(s.substr(j-1 , i-j+1)) && dp[j-1]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];

    }
};
