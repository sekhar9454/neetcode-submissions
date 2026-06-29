class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        int st = 0;

        for (int i = 0; i < n; i++) {

            // Odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if (r - l - 1 > ans) {
                ans = r - l - 1;
                st = l + 1;
            }

            // Even length
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if (r - l - 1 > ans) {
                ans = r - l - 1;
                st = l + 1;
            }
        }

        return s.substr(st, ans);
    }
};