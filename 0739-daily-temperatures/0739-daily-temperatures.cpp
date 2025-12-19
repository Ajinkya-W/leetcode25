class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> result(days, 0);
        stack<int> stk; // <index>

        for(int i = 0; i < days; i++){
            int currTemperature = temperatures[i];
            while(!stk.empty() && temperatures[stk.top()] < currTemperature){
                result[stk.top()] = i - stk.top();
                stk.pop();
            } 
            stk.push(i);
        }
        return result;
    }
};