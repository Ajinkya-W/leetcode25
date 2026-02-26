class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> difference(n+2, 0);
        for(int i = 0; i < bookings.size(); i++){
            int first = bookings[i][0], last = bookings[i][1], seats = bookings[i][2];
            difference[first] += seats; 
            difference[last+1] -= seats;
        }
        vector<int> answer;
        for(int i = 1; i <= n ; i++){
            difference[i] += difference[i-1];
            answer.push_back(difference[i]);
        }
        return answer;
    }
};