class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> suggestionsList;
        string curr = "";
        for(char& c: searchWord){
            curr += c;
            vector<string> suggestion;
            auto it = lower_bound(products.begin(), products.end(), curr); 
            
            for(int i = 0; i < 3 && (it + i) != products.end(); i++){
                string& currProduct = *(it + i); //<- product from products
                if(currProduct.compare(0, curr.size(), curr) != 0) break;                 
                suggestion.push_back(currProduct);
            }
            
            suggestionsList.push_back(suggestion);
        }
        return suggestionsList;
    }
};