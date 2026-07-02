class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &p) {
        // Both strings exhausted
        if (i < 0 && j < 0) return 1;

        // Pattern exhausted but string remains
        if (j < 0) return 0;

        // String exhausted
        if (i < 0) {
            while (j >= 0) {
                if (p[j] == '*')
                    j -= 2;
                else
                    return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Normal character or '.'
        if (p[j] != '*') {
            if (p[j] == '.' || p[j] == s[i])
                return dp[i][j] = solve(i - 1, j - 1, s, p);
            else
                return dp[i][j] = 0;
        }

        // Case 1: '*' matches zero occurrences
        int ans = solve(i, j - 2, s, p);

        // Case 2: '*' matches one or more occurrences
        if (p[j - 1] == '.' || p[j - 1] == s[i])
            ans |= solve(i - 1, j, s, p);

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        dp.assign(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, p);
    }
};