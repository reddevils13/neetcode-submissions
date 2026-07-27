class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        stack<double> s;
        vector<pair<int, int>> car;
        for(int i = 0; i < pos.size(); i++){
            car.push_back({pos[i], speed[i]});
        }

        sort(car.begin(), car.end());
        reverse(car.begin(), car.end());

        int ans = 1;
        double prevTime = (double)(target - car[0].first) / car[0].second;
        for(int i = 1; i < car.size(); i++){
            auto x = car[i];
            double time = (double)(target - x.first) / x.second;
            if (time > prevTime){
                ans++;
                prevTime = time;
            }
        }

        return ans;
    }
};
