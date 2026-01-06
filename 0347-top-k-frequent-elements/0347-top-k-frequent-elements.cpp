class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fmap;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<>> minh;
        for(int num: nums){
            fmap[num]++;            
        }
        for(const auto& [num, freq]: fmap){
            minh.push({freq, num});

            if(minh.size()>k)
                minh.pop();
        }

        vector<int> ans;
        ans.reserve(k);

        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};