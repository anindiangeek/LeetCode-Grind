class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        for(int row = 0; row < n/2; row++)
            for(int col = row; col < n - row - 1; col++)
            {                
                swap(matrix[row][col], matrix[col][n - 1 - row]);
                swap(matrix[row][col], matrix[n - 1 - row][n - 1 - col]);
                swap(matrix[row][col], matrix[n - 1 - col][row]);
            }
    }
};