class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length() , windowSize = s1.length();

        vector<int> fs1(26, 0) , fs2(26,0);
        for(char ch : s1) fs1[ch-'a']++;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            fs2[s2[right] - 'a']++;
            if(right - left +1 == windowSize){
                if(fs2 == fs1) return true;
                fs2[s2[left] - 'a']--;
                left++;
            }
            
        }

        return false;
    }
};
