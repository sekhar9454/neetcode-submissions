class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tp, vector<int>& target) {
        vector<bool>flag(3,false);

        int n = tp.size() , x = target[0] , y = target[1] , z = target[2];
        for(int i = 0 ; i < n ; i++){
            if(flag[0] || (x == tp[i][0] && y >= tp[i][1] && z >= tp[i][2])){
                flag[0] = true;
            }
            if(flag[1] || (y == tp[i][1] && x >= tp[i][0] && z >= tp[i][2])){
                flag[1] = true;
            }
            if(flag[2] || (x >= tp[i][0] && y >= tp[i][1] && z == tp[i][2])){
                flag[2] = true;
            }
        }

        return flag[0] && flag[1] && flag[2];
    }
};
