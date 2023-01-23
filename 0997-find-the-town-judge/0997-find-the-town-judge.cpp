class Solution
{
public:
	int findJudge(int n, vector<vector<int>> &trust)
	{
		if (n == 1)
			return 1;
		if (!size(trust) and n > 1)
			return -1;

		vector<pair<int, bool>> Hash(n + 1, {0, 0});

		for (auto k : trust)
		{
			Hash[k[1]].first++;
			Hash[k[0]].second = true;
		}

		int MaximumFreq = INT_MIN, Town_judge = -1;

		for (int i = 0; i < n; i++)
		{
			if (MaximumFreq < Hash[i + 1].first)
			{
				MaximumFreq = Hash[i + 1].first;
				Town_judge = i + 1;
			}
		}

		if (MaximumFreq != n - 1 or Hash[Town_judge].second)
			return -1;

		return Town_judge;
	}
};