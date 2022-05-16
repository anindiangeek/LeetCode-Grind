class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector <vector <int>> moves = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;
        queue <vector <int>> que;
        if(grid[0][0] || grid[n][m])
            return -1;
        que.push({0, 0, 1});
        while(!que.empty()){
            vector <int> top = que.front();
            que.pop();
            if(top[0] == n && top[1] == m)
                return top[2];
            for(vector <int> move: moves){
                int x = top[0] + move[0], y = top[1] + move[1];
                if( 0 <= x && x <= n && 0 <= y && y <= m && grid[x][y] == 0){
                    grid[x][y] = 1;  // mark visted
                    que.push({x, y, top[2] + 1});
                }
            }
        }
        return -1;
    }
};