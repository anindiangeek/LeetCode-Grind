class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(color == image[sr][sc]) return image;
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};
        
        int rowsize = image.size(), colsize = image[0].size();
        int color2 = image[sr][sc];
        
        queue<pair<int, int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int m = p.first + x[j], n = p.second + y[j];
                
                if(m>=0 and n>=0 and m<rowsize and n<colsize)
                {
                    if (image[m][n] == color2)
                    {
                        q.push({m, n});
                        image[m][n] = color;
                    }
                }
            }
        }
        return image;
    }
};