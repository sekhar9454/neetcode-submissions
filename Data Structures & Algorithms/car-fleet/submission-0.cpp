class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;

        for(int i=0;i<position.size();i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for(auto &[pos, sp] : cars){
            double t = (double)(target - pos) / sp;

            if(t > lastTime){
                fleets++;
                lastTime = t;
            }
        }

        return fleets;
    }
};