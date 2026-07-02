class Solution {
public:
    vector<vector<int>> dp;
    int m, n;

    int dfs(int i, int j, vector<vector<int>>& mat) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if (ni >= 0 && nj >= 0 &&
                ni < m && nj < n &&
                mat[ni][nj] > mat[i][j]) {

                ans = max(ans, 1 + dfs(ni, nj, mat));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};