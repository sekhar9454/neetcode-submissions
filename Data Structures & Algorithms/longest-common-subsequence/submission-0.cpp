class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i , int j , string &t1, string &t2){
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(t1[i] == t2[j]){
            return dp[i][j] = 1 + solve(i-1 , j-1 , t1 , t2);
        }

        return dp[i][j] = max(solve(i-1 , j, t1 , t2) , solve(i , j-1, t1 , t2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length() , n2 = text2.length();
        dp.resize(n1+1 , vector<int>(n2+1 , -1));

        return solve(n1 - 1 , n2 -1 , text1 , text2);
    }
};
