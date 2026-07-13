class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        for (auto &p : points) {
            int x = p[0], y = p[1];
            long long dist = 1LL * x * x + 1LL * y * y;
            pq.emplace(dist, x, y);
        }

        vector<vector<int>> ans;

        while (k--) {
            auto [dist, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }

        return ans;
    }
};