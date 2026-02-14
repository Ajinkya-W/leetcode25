class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        for(string &word: words){
            int tempWordSum = 0;
            for(char &c: word){
                tempWordSum += weights[c-'a'];
            }
            result +=char('a' + (26 -tempWordSum % 26) - 1);
        }
        return result;
    }
};