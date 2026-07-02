class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j , string &s , string &t){
        if(j < 0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int match = 0;
        if(s[i] == t[j]){
            match = solve(i-1 , j-1  , s , t);
        } 

        match += solve(i-1 , j , s , t);

        return dp[i][j] = match;
    }
    int numDistinct(string s, string t) {
        int n1 = s.length() , n2 = t.length();
        dp.assign(n1 , vector<int>(n2 , -1));
        return solve(n1-1 , n2-1 , s , t);    
    }
};
