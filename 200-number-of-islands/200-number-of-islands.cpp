class Solution {
public:
     int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
    void dfs(int p, int q, vector<vector<char>> &grid)
    {
        grid[p][q] = '2';

        for (int i = 0; i < 4; i++)
        {
            if (p + x[i] >= 0 and q + y[i] >= 0 and p + x[i] < grid.size() and q + y[i] < grid[0].size() and grid[p + x[i]][q + y[i]] == '1')
                dfs(p + x[i], q + y[i], grid);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int answer = 0;
        int rows = grid.size(), col = grid[0].size();

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1')
                {
                    answer++;
                    dfs(i, j, grid);
                }

        return answer;
    }
};