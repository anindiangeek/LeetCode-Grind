class Solution {
public:
     vector<int> answer;
    void dfs(int node, int move, int level, int max_level, int res)
    {
        res += node;
        if (level == max_level)
        {
            answer.push_back(res);
            return;
        }
        
        int left = node - move, right = node + move;
        if (right<=9 and left !=right)
            dfs(right, move, level + 1, max_level, res * 10);

        if (left >= 0)
            dfs(left, move, level + 1, max_level, res * 10);
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        for (int i = 1; i <= 9; i++)
            dfs(i, k, 1, n, 0);

        return answer;
    }
};