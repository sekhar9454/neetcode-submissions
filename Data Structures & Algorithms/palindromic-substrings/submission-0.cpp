class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cnt++;
            }

            // Even length
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cnt++;
            }

        }

        return cnt;
    }
};
