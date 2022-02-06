class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int Left{0}, Right{(int)matrix[0].size() - 1}, Top{0}, Bottom{(int)matrix.size() - 1};

        while (Left <= Right and Top <= Bottom)
        {
            for (int i = Left; i <= Right; ++i)
                answer.push_back(matrix[Top][i]);
            ++Top;

            for (int i = Top; i <= Bottom; ++i)
                answer.push_back(matrix[i][Right]);
            --Right;

            if (Top > Bottom or Left > Right)
                break;

            for (int i = Right; i >= Left; --i)
                answer.push_back(matrix[Bottom][i]);
            --Bottom;

            for (int i = Bottom; i >= Top; --i)
                answer.push_back(matrix[i][Left]);
            ++Left;
        }
        return answer;
    }
};