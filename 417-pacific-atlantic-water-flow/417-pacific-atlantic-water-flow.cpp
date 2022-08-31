class Solution 
{
public:
        int x[4] = {0, -1, 0, 1};
    int y[4] = {-1, 0, 1, 0};

    void dfs(int p, int q, vector<vector<int>> &v, vector<vector<int>> &h)
    {
        v[p][q] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = x[i] + p;
            int ny = y[i] + q;

            if (nx >= 0 and nx < h.size() and ny >= 0 and ny < h[0].size())
                if (!v[nx][ny] and h[nx][ny] >= h[p][q])
                    dfs(nx, ny, v, h);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> A(m, vector<int>(n, 0));
        vector<vector<int>> P(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, P, heights);
            dfs(i, n - 1, A, heights);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(0, i, P, heights);
            dfs(m - 1, i, A, heights);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (P[i][j] and A[i][j])
                    result.push_back({i, j});

        return result;
    }
};