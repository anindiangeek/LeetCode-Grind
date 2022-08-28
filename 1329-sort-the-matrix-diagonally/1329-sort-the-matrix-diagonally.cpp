class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
                vector<int> v;
        int rows = mat.size(), cols = mat[0].size();
        for (int x = cols - 1; x >= 0; x--)
        {
            v.clear();
            for (int i = 0, j = x; i < rows and j < cols; i++, j++)
                v.push_back(mat[i][j]);
            sort(v.begin(), v.end());
            for (int i = 0, j = x, k = 0; i < rows and j < cols; i++, j++)
                mat[i][j] = v[k++];
        }

        for (int x = 1; x < rows; x++)
        {
            v.clear();
            for (int i = x, j = 0; i < rows and j < cols; i++, j++)
                v.push_back(mat[i][j]);

            sort(v.begin(), v.end());

            for (int i = x, j = 0, k = 0; i < rows and j < cols; i++, j++)
                mat[i][j] = v[k++];
        }
        return mat;
    }
};