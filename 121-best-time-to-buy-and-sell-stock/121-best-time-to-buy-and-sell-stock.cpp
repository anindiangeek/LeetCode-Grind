class Solution // O(N) S(1)
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int CurrentMinimumValueFound = INT_MAX; // stores minimal left value.
        int Profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            CurrentMinimumValueFound = min(prices[i], CurrentMinimumValueFound);
            Profit = max(Profit, prices[i] - CurrentMinimumValueFound);
        }
        return Profit;
    }
};
