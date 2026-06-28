class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i : nums) mp[i]++;

        vector<pair<int,int>>ans;

        for(auto &[key,v] : mp){
            ans.push_back({key , v});
        }

        sort(ans.begin() , ans.end() , [](pair<int,int>a , pair<int,int>b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });

        vector<int>f;
        for(int i = 0 ; i < k ; i++){
            f.push_back(ans[i].first);
        }

        return f;

    }
};
