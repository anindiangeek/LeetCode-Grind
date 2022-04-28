class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int nRows = heights.size(), nCols = heights[0].size();
        
        vector<vector<int>> efforts(nRows, vector<int>(nCols, rangeValue));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        min_heap.emplace(0, 0);
        
        while(!min_heap.empty()){
            auto top = min_heap.top();
            int effort = top.first;
            int row = top.second / rangeSize, col = top.second % rangeSize;
            min_heap.pop();

            if(row == nRows - 1 && col == nCols - 1) return effort;
            
            if(effort >= efforts[row][col]) continue;
            efforts[row][col] = effort;
            
            for(int d = 0; d < 4; ++d){
                int next_row = row + dirs[d], next_col = col + dirs[d + 1];
                if(next_row < 0 || next_row >= nRows || next_col < 0 || next_col >= nCols) continue;
                
                int next_effort = max(effort, abs(heights[row][col] - heights[next_row][next_col]));
                
                min_heap.emplace(next_effort, next_row * rangeSize + next_col);
            }
        }
        
        return -1;
    }
    
private:
    int dirs[5] = {0, -1, 0, 1, 0};
    const int rangeValue = (int)1e6 + 7;
    const int rangeSize = 100 + 1;
};