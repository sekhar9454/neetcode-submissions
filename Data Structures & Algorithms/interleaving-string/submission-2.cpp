class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int k,
              string &s1, string &s2, string &s3) {

        if (k == s3.length())
            return (i == s1.length() && j == s2.length());

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool ans = false;

        if (i < s1.length() && s1[i] == s3[k])
            ans |= solve(i + 1, j, k + 1, s1, s2, s3);

        if (j < s2.length() && s2[j] == s3[k])
            ans |= solve(i, j + 1, k + 1, s1, s2, s3);

        return dp[i][j][k] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();

        if (n3 != n1 + n2)
            return false;

        dp.assign(n1 + 1,
                  vector<vector<int>>(n2 + 1,
                  vector<int>(n3 + 1, -1)));

        return solve(0, 0, 0, s1, s2, s3);
    }
};