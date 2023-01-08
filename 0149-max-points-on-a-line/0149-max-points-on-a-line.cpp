class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (size(points) < 3)
            return size(points);
        int ans = 0;
        for (auto P1 : points)
        {
            unordered_map<double, int> Hash;
            for (auto P2 : points)
            {
                if (P2 == P1)
                    continue;
                double slope = (P2[0] - P1[0]) ? (((double)P2[1] - P1[1]) / (P2[0] - P1[0])) : INT_MAX;
                Hash[slope]++;
                ans = max(ans, Hash[slope]);
            }
        }
        return ans + 1;
    }
};