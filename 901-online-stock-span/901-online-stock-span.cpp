class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {

    }
    
    int next(int price) {
        int cnt = 0;
        prices.push_back(price);
        for (int j = prices.size() - 1; j >= 0; j--) {
            if (prices[j] <= price) {
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */