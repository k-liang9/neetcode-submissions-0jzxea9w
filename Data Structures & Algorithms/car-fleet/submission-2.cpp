class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs(position.size());
        for (int i = 0; i < position.size(); i++) {
            pairs[i] = {position[i], speed[i]};
        }

        sort(pairs.begin(), pairs.end());

        for (int i = 0; i < position.size(); i++) {
            position[i] = pairs[i].first;
            speed[i] = pairs[i].second;
        }

        double fleet_time = 0;
        int fleets = 0;
        for (int i = position.size()-1; i >= 0; i--) {
            double car_time = (target - position[i]) * 1.0 / speed[i];

            if (fleet_time == 0 || fleet_time < car_time) {
                fleet_time = car_time;
                fleets++;
            }
        }

        return fleets;
    }
};
