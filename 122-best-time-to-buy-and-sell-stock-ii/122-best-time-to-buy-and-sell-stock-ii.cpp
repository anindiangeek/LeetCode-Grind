class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int SubProfit = 0,i = 0, j = 0, n = prices.size();
        while (i < n - 1 && j < n - 1)
        {
            if (prices[i] < prices[i + 1])
            {
                j = i + 1;
                while (j < n - 1 && prices[j] <= prices[j + 1])
                    j++;
                SubProfit += prices[j] - prices[i];
                i = j + 1;
            }
            else
                i++;
        }
        return SubProfit;
    }
};