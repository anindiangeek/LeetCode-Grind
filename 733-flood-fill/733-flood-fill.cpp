class Solution {
public:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int oldcolor)
    {
        image[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int nx = x[i]+sr, ny = y[i]+sc;
            if(nx>=0 and ny>=0 and nx<image.size() and ny<image[0].size())
            {
                if(image[nx][ny]==oldcolor)
                {
                    dfs(image,nx,ny,color, oldcolor);
                }
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(color == image[sr][sc]) return image;
        int M = image.size(), N = image[0].size();
        int oldcolor = image[sr][sc];
        image[sr][sc]=color;
        dfs(image,sr,sc, color, oldcolor);
        return image;
    }
};