class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>idx(26,-1);
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            idx[s[i] - 'a'] = i;
        }
        int st = 0 , rchd = 0;
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            rchd = max(rchd , idx[s[i] - 'a']);
            if(rchd == i){
                ans.push_back(i - st + 1);
                st = i+1;
            }
            
        }

        return ans;
    }
};
