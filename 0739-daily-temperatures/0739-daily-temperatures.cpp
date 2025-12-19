class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        unordered_map<int, int> hmap;
        hmap.reserve(days);
        vector<int> result(days, 0);
        stack<pair<int, int>> stk; // <temp, index>

        for(int i = 0; i < days; i++){
            int currTemperature = temperatures[i];
            while(!stk.empty() && stk.top().first < currTemperature){
                result[stk.top().second] = i - stk.top().second;
                stk.pop();
            } 
            stk.push({currTemperature, i});
        }
        return result;
    }
};