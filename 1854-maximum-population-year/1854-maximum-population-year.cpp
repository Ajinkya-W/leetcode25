class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> delta(102, 0);
        for(auto& log: logs){
            int start = log[0], end = log[1];
            delta[start - 1950]++;
            delta[end - 1950]--;
        }
        int peopleAliveNow = 0, maxAlivePopulation = 0, bestYearToLive;
        for(int i = 0; i < delta.size(); i++){
            int val = delta[i];
            peopleAliveNow += val;
            if(maxAlivePopulation < peopleAliveNow){
                maxAlivePopulation = peopleAliveNow;
                bestYearToLive = i + 1950;
            }
        }
        return bestYearToLive;
    }
};