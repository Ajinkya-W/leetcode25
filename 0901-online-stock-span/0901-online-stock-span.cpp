class StockSpanner {
private:
    struct stock{
        int price;
        int span;
    };
public:
    stack<stock> stkSpan; // price, span
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!stkSpan.empty() && stkSpan.top().price <= price){
            int topElementSpan = stkSpan.top().span;
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