class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> charCountStack;
        for(char currChar: s){
            if(!charCountStack.empty() && charCountStack.back().first==currChar){
                charCountStack.back().second++;
                if (charCountStack.back().second == k) {
                    charCountStack.pop_back();
                }
            } else{
                charCountStack.push_back({currChar,1});
            }
        }
        string result="";
        while(!charCountStack.empty()){
            int charRepeatTime = charCountStack.front().second;
            while(charRepeatTime--){
                result+=charCountStack.front().first;
            }
            charCountStack.pop_front();
        }
        return result;
    }
};