class Solution {
   public:
    bool dfs(int i, int j, string& word, int idx, vector<vector<char>>& b,
             vector<vector<bool>>& vis) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i == b.size() || j == b[0].size() || vis[i][j]) return false;
        if (b[i][j] != word[idx]) return false;

        vis[i][j] = true;
        bool found = dfs(i + 1, j, word, idx + 1, b, vis) || dfs(i - 1, j, word, idx + 1, b, vis) ||
                     dfs(i, j + 1, word, idx + 1, b, vis) || dfs(i, j - 1, word, idx + 1, b, vis);

        vis[i][j] = false;  // Backtrack

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        bool ans = false;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vis.assign(m, vector<bool>(n, false));
                    ans |= dfs(i, j, word, 0, board, vis);
                }

                if (ans) return true;
            }
        }

        return false;
    }
};
