class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int n = board.size(), block_size = 3;
        // checking rows only
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> Hash;
            for (int j = 0; j < n; j++)
                if (board[i][j] != '.')
                {
                    if (Hash.find(board[i][j]) != Hash.end())
                        return false;
                    else
                        Hash.insert(board[i][j]);
                }
        }

        // checking columns
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> Hash;
            for (int j = 0; j < n; j++)
                if (board[j][i] != '.')
                {
                    if (Hash.find(board[j][i]) != Hash.end())
                        return false;
                    else
                        Hash.insert(board[j][i]);
                }
        }

        // checking blocks 3x3
        for (int i = 0; i < n; i += 3)
            for (int k = 0; k < n; k += 3)
            {
                unordered_set<char> Hash;
                for (int p = k; p < k + block_size; p++)
                    for (int q = i; q < i + block_size; q++)
                        if (board[p][q] != '.')
                        {
                            if (Hash.find(board[p][q]) != Hash.end())
                                return false;
                            else
                                Hash.insert(board[p][q]);
                        }
            }
        return true;
        
    }
};