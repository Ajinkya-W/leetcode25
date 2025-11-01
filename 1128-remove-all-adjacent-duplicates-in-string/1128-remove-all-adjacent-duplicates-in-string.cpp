class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> uniqueElementStack;
        for(char currChar: s){
            if(!uniqueElementStack.empty() && uniqueElementStack.top()==currChar){
                uniqueElementStack.pop();
            } else{
                uniqueElementStack.push(currChar);
            }
        }
        string result="";
        while(!uniqueElementStack.empty()){
            result+=uniqueElementStack.top();
            uniqueElementStack.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};