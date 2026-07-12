class TimeMap {
public:
    unordered_map<string , vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
       auto &v = mp[key];

    auto it = upper_bound(v.begin(), v.end(),
                          make_pair(timestamp, string(1, char(127))));

    if (it == v.begin())
        return "";

    --it;
    return it->second;
    }
};
