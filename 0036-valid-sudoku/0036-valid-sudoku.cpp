class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //checking rows only
        for(int i=0;i<9;i++)
        {
            unordered_set<char> Hash;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                if(Hash.find(board[i][j])!=Hash.end())
                    return false;
                else
                    Hash.insert(board[i][j]);
                }
            }
        }
        
        //checking columns
        for(int i=0;i<9;i++)
        {
            unordered_set<char> Hash;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                if(Hash.find(board[j][i])!=Hash.end())
                    return false;
                else
                    Hash.insert(board[j][i]);
                }
            }
        }
        
        // checking blocks 3x3

        for(int i=0;i<9;i+=3)
        {
            for(int k=0;k<9;k+=3)
            {
                unordered_set<char> Hash;
                for(int p=k;p<k+3;p++)
                {
                    for(int q=i;q<i+3;q++)
                    {
                        if(board[p][q]!='.')
                        {
                            if(Hash.find(board[p][q])!=Hash.end())
                                   return false;
                            else
                               Hash.insert(board[p][q]);
                        }
                        
                    }
                }
            }
        }
        return true;
    }
};