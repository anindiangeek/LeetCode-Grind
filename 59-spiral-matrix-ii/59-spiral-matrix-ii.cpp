class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
         if (n==0) return {};
        if (n==1) return {{1}};
         vector<vector<int>> answer(n, vector<int>(n));
        // Top Bottom Left Right.
        int T, B, L, R;
        T = L = 0;
        B = R = n - 1;

        int value = 1;
        while (value <= n * n)
        {
            // L to R;
            for (int i = L; i <= R; i++)
                answer[T][i] = value++;
            T++;

            // T to B
            for (int i = T; i <= B; i++)
                answer[i][R] = value++;
            R--;

            // R to L
            for (int i = R; i >= L; i--)
                answer[B][i] = value++;
            B--;

            // B to T
            for (size_t i = B; i >= T; i--)
                answer[i][L] = value++;
            L++;
        }
        return answer;
    }
};