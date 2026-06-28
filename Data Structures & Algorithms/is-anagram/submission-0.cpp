class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>fs(26 , 0) , ft(26,0);

        for(char ch : s) fs[ch-'a']++;
        for(char ch : t) ft[ch-'a']++;

        return fs == ft;
    }
};
