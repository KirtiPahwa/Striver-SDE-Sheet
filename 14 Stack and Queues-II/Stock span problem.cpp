class StockSpanner
{
public:
    int i;
    stack<pair<int, int>> s;
    StockSpanner()
    {
        i = -1;
    }

    int next(int price)
    {
        i++;
        int ans = -1;
        while (!s.empty() && s.top().first <= price)
        {
            s.pop();
        }
        if (!s.empty())
        {
            ans = i - s.top().second;
        }
        else
        {
            ans = i - (ans);
        }
        s.push({price, i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
