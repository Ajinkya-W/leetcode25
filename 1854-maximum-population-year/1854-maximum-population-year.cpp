class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxYear;
        int maxPopulation = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // {birthYear, deathYear}

        for(int i = 0; i < logs.size(); i++){
            int bornYear = logs[i][0];
            int deathYear = logs[i][1];

            pq.push(make_pair(bornYear, 1));
            pq.push(make_pair(deathYear, -1));
        }
        int population = 0;
        while(!pq.empty()){
            bool isDeathYear = pq.top().second == -1? 1: 0;
            int currYear = pq.top().first;
            pq.pop();
            if(isDeathYear){
                population--;
            } else{
                population++;
            }

            if(maxPopulation < population){
                maxPopulation = population;
                maxYear = currYear;
            }
        }
        return maxYear;
    }
};