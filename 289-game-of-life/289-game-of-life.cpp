class Solution
{
  public:
    int CountNeighbors(vector<vector<int>> &board, int x, int y)
    {
        int cnt{0};
        int r = board.size(), c = board[0].size();
        cnt += (x + 1 < r && board[x + 1][y]) ? 1 : 0;
        cnt += (y + 1 < c && board[x][y + 1]) ? 1 : 0;
        cnt += (x > 0 && board[x - 1][y]) ? 1 : 0;
        cnt += (y > 0 && board[x][y - 1]) ? 1 : 0;
        cnt += (x + 1 < r && y + 1 < c && board[x + 1][y + 1]) ? 1 : 0;
        cnt += (x > 0 && y > 0 && board[x - 1][y - 1]) ? 1 : 0;
        cnt += (x > 0 && y < c - 1 && board[x - 1][y + 1]) ? 1 : 0;
        cnt += (x + 1 < r && y > 0 && board[x + 1][y - 1]) ? 1 : 0;

        return cnt;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int r = board.size(), c = board[0].size();
        vector<vector<int>> temp = board;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int NOLN = CountNeighbors(temp, i, j);
                if (temp[i][j] && NOLN < 2)
                    board[i][j] = 0;
                else if (temp[i][j] && NOLN == 2 or NOLN == 3)
                    board[i][j] = 1;
                else if (temp[i][j] && NOLN > 3)
                    board[i][j] = 0;
                else if (temp[i][j] == 0 && NOLN == 3)
                    board[i][j] = 1;
            }
        }
    }
};