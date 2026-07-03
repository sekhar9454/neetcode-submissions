class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mp;
        for (int x : hand)
            mp[x]++;

        for (auto &[k, v] : mp) {
            if (v == 0) continue;

            int cnt = v;   // number of groups starting here

            for (int i = k; i < k + groupSize; i++) {
                if (mp[i] < cnt)
                    return false;
                mp[i] -= cnt;
            }
        }

        return true;
    }
};