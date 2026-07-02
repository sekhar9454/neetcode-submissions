class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j , string &w1 , string &w2){
        if(i < 0) return j + 1;   // insert remaining characters
        if(j < 0) return i + 1;   // delete remaining characters

        if(dp[i][j] != -1) return dp[i][j];

        
        if(w1[i] == w2[j]){
            return dp[i][j] = solve(i-1 , j-1 , w1 , w2);
        }

        return dp[i][j] =1 + min({
            solve(i , j-1 , w1 , w2),
            solve(i-1 , j , w1 , w2),
            solve(i-1 , j-1 , w1 , w2)
        });
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size() , n2 = word2.size();
        dp.assign(n1 , vector<int>(n2 , -1));

        return solve(n1-1 , n2-1 , word1 , word2);

    }
};
