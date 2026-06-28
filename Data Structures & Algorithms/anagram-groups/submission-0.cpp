class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mp;

        for(string word : strs){
            vector<int>f(26,0);
            for(char ch : word){
                f[ch-'a']++;
            }
            string key = "";
            for(int i = 0 ; i < 26 ; i++){
                key+=to_string(f[i]);
                key+= '#';
            }
            mp[key].push_back(word);
        }

        vector<vector<string>>ans;
        for(auto &[k,v] : mp){
            ans.push_back(v);
        }

        return ans;
    }
};
