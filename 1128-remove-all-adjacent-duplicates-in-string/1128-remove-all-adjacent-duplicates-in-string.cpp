class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> uniqueElementStack;
        for(char currChar: s){
            if(!uniqueElementStack.empty() && uniqueElementStack.back()==currChar){
                uniqueElementStack.pop_back();
            } else{
                uniqueElementStack.push_back(currChar);
            }
        }
        string result="";
        while(!uniqueElementStack.empty()){
            result+=uniqueElementStack.front();
            uniqueElementStack.pop_front();
        }
        
        return result;
    }
};