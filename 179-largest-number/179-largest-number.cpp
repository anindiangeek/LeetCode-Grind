class Solution {
public:
    static bool comp(const string &p, const string &q)
    {
        return p + q > q + p;
    }
    string largestNumber(vector<int> &nums)
    {
        string answer;
        vector<vector<string>> bins(10);

        for (auto value : nums)
            bins[(value != 0 and (int) log10(value)) ? (value / (int)(pow(10, (int)log10(value)))) : value].push_back(
                to_string(value));

        if (bins[0].size() == nums.size())
            return "0";

        for (int i = 0; i < 10; i++)
            sort(bins[i].begin(), bins[i].end(), comp);

        for (int i = 9; i >= 0; i--)
            for (int j = 0; j < bins[i].size(); j++)
                answer += (bins[i][j]);

        return answer;
    }
};