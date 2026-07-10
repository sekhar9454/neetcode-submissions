class Solution {
public:
    bool valid(vector<int>&fs , vector<int>&ft){
        for(int i= 0 ; i < 256 ; i++){
            if(fs[i] < ft[i]) return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        vector<int>ft(256 , 0 ) , fs(256,0);

        int left = 0 , n = s.length();
        int ans = INT_MAX , st , end;

        for(char ch : t) ft[ch]++;
        for(int right = 0 ; right < n ; right++){
            fs[s[right]]++;

            while(valid(fs , ft)){
                fs[s[left]]--;
                if(ans > right - left+1){
                    ans = right -left+1;
                    st = left;
                    end = right;
                }
                left++;
            }

        }
        if(ans == INT_MAX) return "";
        return s.substr(st , ans);
    }
};
