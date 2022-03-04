class Solution {
public:
    double champagneTower(int poured, int r, int c) {
         double dp[101][101] = {0.0};
        dp[0][0] = poured;
        for (int i=0;i<100;i++)
            for (int j=0;j<=i;j++) 
                if (dp[i][j]>=1){ //if current glass is full
                    dp[i+1][j]+= (dp[i][j]-1)/2.0; //left of next row
                    dp[i+1][j+1]+=(dp[i][j]-1)/2.0; //right of next row
                    dp[i][j] = 1; //current glass remains as 1
                }
        return dp[r][c];
    }
};