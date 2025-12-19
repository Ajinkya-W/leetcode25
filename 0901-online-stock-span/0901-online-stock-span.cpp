class StockSpanner {
public:
    stack<pair<int, int>> stkSpan; // price, span
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!stkSpan.empty() && stkSpan.top().first <= price){
            int topElementSpan = stkSpan.top().second;
            span += topElementSpan;
            stkSpan.pop();
        }
        stkSpan.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */