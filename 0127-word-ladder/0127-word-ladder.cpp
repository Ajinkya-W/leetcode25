class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // p0: creating a patternmap
        bool foundEnd = false;
        unordered_map<string, vector<string>> patternMap;
        for(const auto& word: wordList){
            if (word == endWord) foundEnd = true;
            for(int i = 0; i < word.size(); i++){
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }
        if(!foundEnd) return 0;

        // Phase 1: BFS Setup
        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        int steps = 1; // The problem asks for number of words, not edges.

        // Phase 2: BFS Layer Pattern (from your cheat sheet)
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return steps;

                // Generate patterns for the current word
                for (int i = 0; i < curr.length(); i++) {
                    string pattern = curr;
                    pattern[i] = '*';

                    // Look up neighbors in the pattern map
                    for (const string& neighbor : patternMap[pattern]) {
                        if (visited.find(neighbor) == visited.end()) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                    // OPTIMIZATION: Once a pattern is used, clear it to avoid redundant checks
                    patternMap.erase(pattern); 
                }
            }
            steps++;
        }
    return 0;
    }
};
/*
Word: HIT $\to$ COG. List: [HOT, DOT, DOG, LOT, LOG, COG]
Layer 1: HIT (Steps: 1)Patterns: *IT, H*T, HI*H*T finds HOT.
Layer 2: HOT (Steps: 2)Patterns: *OT, H*T, HO**OT finds DOT, LOT.
Layer 3: DOT, LOT (Steps: 3)DOT patterns find DOG.LOT patterns find LOG.
Layer 4: DOG, LOG (Steps: 4)DOG patterns find COG.
Layer 5: COG (Steps: 5)curr == endWord 
Return 5.
*/