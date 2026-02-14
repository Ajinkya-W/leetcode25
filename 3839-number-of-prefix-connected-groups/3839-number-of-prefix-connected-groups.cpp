class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> groupsCountMap;
        for(string word: words){
            if(word.size() >= k){
                string prefix = word.substr(0, k);
                groupsCountMap[prefix]+=1;
            }
        }
        int groups = 0;
        for(auto entry: groupsCountMap){
            if(entry.second >=2){
                groups++;
                cout<<entry.first<<endl;
            }
        }
        return groups;
    }
};