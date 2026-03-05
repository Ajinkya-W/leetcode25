class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap; 
        for (int num : piles) {
            maxHeap.push(num);
        }
        while (k > 0 && !maxHeap.empty()) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxHeap.push((maxElement+1) / 2);
            k--;
        }
        int totalSumAfterKOps = 0;
        while (!maxHeap.empty()) {
            int element = maxHeap.top();
            maxHeap.pop();
            totalSumAfterKOps += element;
        }
        return totalSumAfterKOps;
    }
};