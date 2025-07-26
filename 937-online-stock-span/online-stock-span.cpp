class StockSpanner {
    vector<int> prices;

public:
    int next(int price) {
        int span = 1;
        int i = prices.size() - 1;

        while (i >= 0 && prices[i] <= price) {
            span++;
            i--;
        }

        prices.push_back(price);
        return span;
    }
};
